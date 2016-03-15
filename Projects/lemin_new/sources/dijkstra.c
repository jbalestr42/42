/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:15:51 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/15 14:07:49 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// A utility function to check if the given heap is ampty or not
static int				is_empty(t_min_heap* heap)
{
	return (heap->size == 0);
}

// Standard function to extract minimum node from heap
static t_min_heap_node	*extract_min(t_min_heap* heap)
{
	if (is_empty(heap))
		return (NULL);

	// Store the root node
	t_min_heap_node* root = heap->array[0];

	// Replace root node with last node
	t_min_heap_node* lastNode = heap->array[heap->size - 1];
	heap->array[0] = lastNode;

	// Update position of last node
	heap->pos[root->v] = heap->size - 1;
	heap->pos[lastNode->v] = 0;

	// Reduce heap size and heapify root
	--heap->size;
	min_heapify(heap, 0);

	return (root);
}

// Function to decreasy dist value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
static void				decrease_key(t_min_heap *heap, int v, int dist)
{
	// Get the index of v in  heap array
	int i = heap->pos[v];

	// Get the node and update its dist value
	heap->array[i]->dist = dist;

	// Travel up while the complete tree is not hepified.
	// This is a O(Logn) loop
	while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist)
	{
		// Swap this node with its parent
		heap->pos[heap->array[i]->v] = (i-1)/2;
		heap->pos[heap->array[(i-1)/2]->v] = i;
		swap_min_heap_node(&heap->array[i],  &heap->array[(i - 1) / 2]);

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
	// heap represents set E
	t_min_heap* heap = create_min_heap(V);

	v = 0;
	// Initialize min heap with all vertices. dist value of all vertices 
	while (v < V)
	{
		parent[v] = -1;
		dist[v] = INT_MAX;
		heap->array[v] = new_min_heap_node(v, dist[v]);
		heap->array_tmp[v] = heap->array[v];
		heap->pos[v] = v;
		v++;
	}

	// Make dist value of src vertex as 0 so that it is extracted first
	heap->array[src]->v = src;
	heap->array[src]->dist = dist[src];
	dist[src] = 0;
	decrease_key(heap, src, dist[src]);

	// In the followin loop, min heap contains all nodes
	// whose shortest distance is not yet finalized.
	while (!is_empty(heap))
	{
		// Extract the vertex with minimum distance value
		t_min_heap_node* heapNode = extract_min(heap);
		int u = heapNode->v; // Store the extracted vertex number

		// Traverse through all adjacent vertices of u (the extracted
		// vertex) and update their distance values
		t_adj_list_node* pCrawl = graph->array[u].head;
		while (pCrawl != NULL)
		{
			int v = pCrawl->dest;

			// If shortest distance to v is not finalized yet, and distance to v
			// through u is less than its previously calculated distance
			if (is_in_min_heap(heap, v) && dist[u] != INT_MAX && pCrawl->weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + pCrawl->weight;
				parent[v] = u;

				// update distance value in min heap also
				decrease_key(heap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
	}
	ant_stuff(graph, parent, src, find_name(graph, graph->end));
	destroy_min_heap(heap);
}

