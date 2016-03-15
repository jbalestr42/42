/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_heap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:48:35 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/15 17:03:47 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_min_heap_node		*new_min_heap_node(int v, int dist)
{
	t_min_heap_node	*node;

	node = (t_min_heap_node*)malloc(sizeof(t_min_heap_node));
	node->v = v;
	node->dist = dist;
	return (node);
}

t_min_heap			*create_min_heap(int capacity, int *parent, int *dist, int src)
{
	t_min_heap		*min_heap;
	int				i;

	min_heap = (t_min_heap*)malloc(sizeof(t_min_heap));
	min_heap->pos = (int *)malloc(capacity * sizeof(int));
	min_heap->size = capacity;
	min_heap->capacity = capacity;
	min_heap->array = (t_min_heap_node**)malloc(capacity * sizeof(t_min_heap_node*));
	min_heap->array_tmp = (t_min_heap_node**)malloc(capacity * sizeof(t_min_heap_node*));
	i = 0;
	while (i < capacity)
	{
		parent[i] = -1;
		dist[i] = INT_MAX;
		min_heap->array[i] = new_min_heap_node(i, INT_MAX);
		min_heap->array_tmp[i] = min_heap->array[i];
		min_heap->pos[i] = i;
		i++;
	}
	min_heap->array[src]->v = src;
	min_heap->array[src]->dist = dist[src];
	dist[src] = 0;
	return (min_heap);
}

void				swap_min_heap_node(t_min_heap_node **a, t_min_heap_node **b)
{
	t_min_heap_node	*t;

	t = *a;
	*a = *b;
	*b = t;
}

// A standard function to heapify at given idx
// This function also updates position of nodes when they are swapped.
// Position is needed for decreaseKey()
void				min_heapify(t_min_heap *heap, int idx)
{
	t_min_heap_node	*smallestNode;
	t_min_heap_node	*idxNode;
	int				smallest;
	int				left;
	int				right;

	smallest = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;
	if (left < heap->size && heap->array[left]->dist < heap->array[smallest]->dist)
		smallest = left;
	if (right < heap->size && heap->array[right]->dist < heap->array[smallest]->dist)
		smallest = right;
	if (smallest != idx)
	{
		// The nodes to be swapped in min heap
		smallestNode = heap->array[smallest];
		idxNode = heap->array[idx];
		// Swap positions
		heap->pos[smallestNode->v] = idx;
		heap->pos[idxNode->v] = smallest;
		// Swap nodes
		swap_min_heap_node(&heap->array[smallest], &heap->array[idx]);
		min_heapify(heap, smallest);
	}
}

int					is_in_min_heap(t_min_heap *heap, int v)
{
	if (heap->pos[v] < heap->size)
		return 1;
	return 0;
}
