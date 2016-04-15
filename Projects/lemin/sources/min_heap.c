/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_heap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:48:35 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/04 10:30:00 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_min_heap_node		*new_min_heap_node(int idx, int dist)
{
	t_min_heap_node	*node;

	node = (t_min_heap_node*)malloc(sizeof(t_min_heap_node));
	node->idx = idx;
	node->dist = dist;
	return (node);
}

t_min_heap			*create_min_heap(int capacity, int *parent, int *dist,
		int src)
{
	t_min_heap		*min_heap;
	int				i;

	min_heap = (t_min_heap*)malloc(sizeof(t_min_heap));
	min_heap->pos = (int *)malloc(capacity * sizeof(int));
	min_heap->size = capacity;
	min_heap->capacity = capacity;
	min_heap->array = (t_min_heap_node**)malloc(capacity
			* sizeof(t_min_heap_node*));
	min_heap->array_tmp = (t_min_heap_node**)malloc(capacity
			* sizeof(t_min_heap_node*));
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
	min_heap->array[src]->idx = src;
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

void				update_nodes(t_min_heap *heap, int idx)
{
	t_min_heap_node	*smallest_node;
	t_min_heap_node	*idx_node;
	int				sm;
	int				left;
	int				right;

	sm = idx;
	left = 2 * idx + 1;
	right = 2 * idx + 2;
	if (left < heap->size && heap->array[left]->dist < heap->array[sm]->dist)
		sm = left;
	if (right < heap->size && heap->array[right]->dist < heap->array[sm]->dist)
		sm = right;
	if (sm != idx)
	{
		smallest_node = heap->array[sm];
		idx_node = heap->array[idx];
		heap->pos[smallest_node->idx] = idx;
		heap->pos[idx_node->idx] = sm;
		swap_min_heap_node(&heap->array[sm], &heap->array[idx]);
		update_nodes(heap, sm);
	}
}

int					contains(t_min_heap *heap, int idx)
{
	if (heap->pos[idx] < heap->size)
		return (1);
	return (0);
}
