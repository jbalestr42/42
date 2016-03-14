/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:15:51 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/14 17:09:37 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// A utility function to check if the given minHeap is ampty or not
static int				is_empty(t_min_heap* minHeap)
{
	return minHeap->size == 0;
}

// Standard function to extract minimum node from heap
static t_min_heap_node	*extract_min(t_min_heap* minHeap)
{
	if (is_empty(minHeap))
		return NULL;

	// Store the root node
	t_min_heap_node* root = minHeap->array[0];

	// Replace root node with last node
	t_min_heap_node* lastNode = minHeap->array[minHeap->size - 1];
	minHeap->array[0] = lastNode;

	// Update position of last node
	minHeap->pos[root->v] = minHeap->size-1;
	minHeap->pos[lastNode->v] = 0;

	// Reduce heap size and heapify root
	--minHeap->size;
	min_heapify(minHeap, 0);

	return root;
}

// Function to decreasy dist value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
static void				decrease_key(t_min_heap *minHeap, int v, int dist)
{
	// Get the index of v in  heap array
	int i = minHeap->pos[v];

	// Get the node and update its dist value
	minHeap->array[i]->dist = dist;

	// Travel up while the complete tree is not hepified.
	// This is a O(Logn) loop
	while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
	{
		// Swap this node with its parent
		minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
		minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
		swap_min_heap_node(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);

		// move to parent index
		i = (i - 1) / 2;
	}
}

// The main function that calulates distances of shortest paths from src to all
// vertices. It is a O(ELogV) function
void dijkstra(t_graph* graph)
{
	int V = graph->V;// Get the number of vertices in graph
	int dist[V];      // dist values used to pick minimum weight edge in cut
	int parent[V];
	int	v;
	int	src;

	src = find_name(graph, graph->start);
	// minHeap represents set E
	t_min_heap* minHeap = create_min_heap(V);

	v = 0;
	// Initialize min heap with all vertices. dist value of all vertices 
	while (v < V)
	{
		parent[v] = -1;
		dist[v] = INT_MAX;
		minHeap->array[v] = new_min_heap_node(v, dist[v]);
		minHeap->pos[v] = v;
		v++;
	}

	// Make dist value of src vertex as 0 so that it is extracted first
	//minHeap->array[src] = new_min_heap_node(src, dist[src]); // TODO free before ?
	minHeap->array[src]->v = src;
	minHeap->array[src]->dist = dist[src];
	//minHeap->pos[src]   = src; //TODO useless ?
	dist[src] = 0;

	decrease_key(minHeap, src, dist[src]);

	// Initially size of min heap is equal to V
	minHeap->size = V;

	// In the followin loop, min heap contains all nodes
	// whose shortest distance is not yet finalized.
	while (!is_empty(minHeap))
	{
		// Extract the vertex with minimum distance value
		t_min_heap_node* minHeapNode = extract_min(minHeap);
		int u = minHeapNode->v; // Store the extracted vertex number

		// Traverse through all adjacent vertices of u (the extracted
		// vertex) and update their distance values
		t_adj_list_node* pCrawl = graph->array[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			// If shortest distance to v is not finalized yet, and distance to v
			// through u is less than its previously calculated distance
			if (is_in_min_heap(minHeap, v) && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + pCrawl->weight;
				parent[v] = u;

				// update distance value in min heap also
				decrease_key(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
	}

	// print the calculated shortest distances
	//printArr(dist, V);
	ant_stuff(graph, parent, src, find_name(graph, graph->end));
	//printPath(graph, parent, src, find_name(graph, graph->end));
}

