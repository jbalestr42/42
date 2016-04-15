/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:23:50 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/04 10:27:18 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void			free_list(t_adj_list_node *list)
{
	t_adj_list_node	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

static void			free_array(t_adj_list *array, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		if (array[i].head)
			free_list(array[i].head);
		i++;
	}
	free(array);
}

void				destroy_graph(t_graph *graph)
{
	int				i;

	if (graph)
	{
		if (graph->heap)
			destroy_min_heap(graph->heap);
		if (graph->array)
			free_array(graph->array, graph->count);
		if (graph->room_name)
		{
			i = 0;
			while (i < graph->count)
			{
				if (graph->room_name[i])
					free(graph->room_name[i]);
				i++;
			}
			free(graph->room_name);
		}
		if (graph->start)
			free(graph->start);
		if (graph->end)
			free(graph->end);
		free(graph);
	}
}

void				destroy_min_heap(t_min_heap *heap)
{
	int				i;

	i = 0;
	if (heap)
	{
		if (heap->pos)
			free(heap->pos);
		if (heap->array)
		{
			while (i < heap->capacity)
			{
				if (heap->array_tmp[i])
					free(heap->array_tmp[i]);
				i++;
			}
			free(heap->array);
			free(heap->array_tmp);
		}
		free(heap);
	}
}

void				destroy_result(t_ant **ants, int ant_size, int *path,
		int *room_valid)
{
	int				i;

	if (ants)
	{
		i = 0;
		while (i < ant_size)
		{
			if (ants[i])
				free(ants[i]);
			i++;
		}
		free(ants);
	}
	if (path)
		free(path);
	if (room_valid)
		free(room_valid);
}
