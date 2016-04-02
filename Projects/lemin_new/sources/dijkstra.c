/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:15:51 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/15 16:56:43 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// A utility function to check if the given heap is ampty or not
static int				is_empty(t_min_heap *heap)
{
	return (heap->size == 0);
}

// Standard function to extract minimum node from heap
static t_min_heap_node	*extract_min(t_min_heap *heap)
{
	t_min_heap_node		*root;
	t_min_heap_node		*last_node;

	if (is_empty(heap))
		return (NULL);
	// Store the root node
	root = heap->array[0];
	// Replace root node with last node
	last_node = heap->array[heap->size - 1];
	heap->array[0] = last_node;
	// Update position of last node
	heap->pos[root->v] = heap->size - 1;
	heap->pos[last_node->v] = 0;
	// Reduce heap size and heapify root
	--heap->size;
	min_heapify(heap, 0);
	return (root);
}

// Function to decreasy dist value of a given vertex v. This function
// uses pos[] of min heap to get the current index of node in min heap
static void				decrease_key(t_min_heap *heap, int v, int dist)
{
	int i;

	i = heap->pos[v];
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

void					dijkstra(t_graph *graph)
{
	int					dist[graph->V];
	int					parent[graph->V];
	int					u;
	int					v;
	t_adj_list_node		*tmp;

	graph->heap = create_min_heap(graph->V, parent, dist, graph->start_idx);
	decrease_key(graph->heap, graph->start_idx, dist[graph->start_idx]);
	while (!is_empty(graph->heap))
	{
		u = extract_min(graph->heap)->v;
		tmp = graph->array[u].head;
		while (tmp != NULL)
		{
			v = tmp->dest;
			if (is_in_min_heap(graph->heap, v) && dist[u] != INT_MAX && tmp->weight + dist[u] < dist[v])
			{
				dist[v] = dist[u] + tmp->weight;
				parent[v] = u;
				decrease_key(graph->heap, v, dist[v]);
			}
			tmp = tmp->next;
		}
	}
	ant_stuff(graph, parent, graph->start_idx, graph->end_idx);
}
