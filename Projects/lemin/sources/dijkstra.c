/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:15:51 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/04 10:31:55 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int				is_empty(t_min_heap *heap)
{
	return (heap->size == 0);
}

static t_min_heap_node	*extract_min(t_min_heap *heap)
{
	t_min_heap_node		*root;
	t_min_heap_node		*last_node;

	if (is_empty(heap))
		return (NULL);
	root = heap->array[0];
	last_node = heap->array[heap->size - 1];
	heap->array[0] = last_node;
	heap->pos[root->idx] = heap->size - 1;
	heap->pos[last_node->idx] = 0;
	--heap->size;
	update_nodes(heap, 0);
	return (root);
}

static void				decrease_key(t_min_heap *heap, int idx, int dist)
{
	int					i;

	i = heap->pos[idx];
	heap->array[i]->dist = dist;
	while (i && heap->array[i]->dist < heap->array[(i - 1) / 2]->dist)
	{
		heap->pos[heap->array[i]->idx] = (i - 1) / 2;
		heap->pos[heap->array[(i - 1) / 2]->idx] = i;
		swap_min_heap_node(&heap->array[i], &heap->array[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

static int				is_v(int *dist, int min, int idx, int weight)
{
	if (dist[min] != INT_MAX && weight + dist[min] < dist[idx])
		return (1);
	return (0);
}

void					dijkstra(t_graph *graph)
{
	int					dist[graph->count];
	int					parent[graph->count];
	int					min;
	int					idx;
	t_adj_list_node		*tmp;

	graph->heap = create_min_heap(graph->count, parent, dist, graph->start_idx);
	decrease_key(graph->heap, graph->start_idx, dist[graph->start_idx]);
	while (!is_empty(graph->heap))
	{
		min = extract_min(graph->heap)->idx;
		tmp = graph->array[min].head;
		while (tmp != NULL)
		{
			idx = tmp->dest;
			if (contains(graph->heap, idx) && is_v(dist, min, idx, tmp->weight))
			{
				dist[idx] = dist[min] + tmp->weight;
				parent[idx] = min;
				decrease_key(graph->heap, idx, dist[idx]);
			}
			tmp = tmp->next;
		}
	}
	ant_stuff(graph, parent, graph->start_idx, graph->end_idx);
}
