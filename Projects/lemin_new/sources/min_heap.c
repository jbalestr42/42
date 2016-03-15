/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_heap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:48:35 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/15 14:07:13 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// A utility function to create a new Min Heap Node
t_min_heap_node		*new_min_heap_node(int v, int dist)
{
	t_min_heap_node	*node;

	node = (t_min_heap_node*)malloc(sizeof(t_min_heap_node));
	node->v = v;
	node->dist = dist;
	return (node);
}

// A utility function to create a Min Heap
t_min_heap			*create_min_heap(int capacity)
{
	t_min_heap		*min_heap;

	min_heap = (t_min_heap*)malloc(sizeof(t_min_heap));
	min_heap->pos = (int *)malloc(capacity * sizeof(int));
	min_heap->size = capacity;
	min_heap->capacity = capacity;
	min_heap->array = (t_min_heap_node**)malloc(capacity * sizeof(t_min_heap_node*));
	min_heap->array_tmp = (t_min_heap_node**)malloc(capacity * sizeof(t_min_heap_node*));
	return (min_heap);
}

// A utility function to swap two nodes of min heap. Needed for min heapify
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
		t_min_heap_node *smallestNode = heap->array[smallest];
		t_min_heap_node *idxNode = heap->array[idx];
		// Swap positions
		heap->pos[smallestNode->v] = idx;
		heap->pos[idxNode->v] = smallest;
		// Swap nodes
		swap_min_heap_node(&heap->array[smallest], &heap->array[idx]);
		min_heapify(heap, smallest);
	}
}

// A utility function to check if a given vertex
// 'v' is in min heap or not
int					is_in_min_heap(t_min_heap *heap, int v)
{
	if (heap->pos[v] < heap->size)
		return 1;
	return 0;
}
