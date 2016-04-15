/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:22:54 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/02 18:04:05 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_graph				*create_graph(void)
{
	t_graph			*graph;

	if (!(graph = (t_graph*)malloc(sizeof(t_graph))))
		return (NULL);
	graph->start = NULL;
	graph->end = NULL;
	graph->room_count = 0;
	graph->room_name = NULL;
	graph->array = NULL;
	graph->heap = NULL;
	return (graph);
}

void				add_edge(t_graph *graph, int src, int dest, int weight)
{
	t_adj_list_node	*node;

	node = new_adj_list_node(dest, weight);
	node->next = graph->array[src].head;
	graph->array[src].head = node;
	node = new_adj_list_node(src, weight);
	node->next = graph->array[dest].head;
	graph->array[dest].head = node;
}

t_adj_list_node		*new_adj_list_node(int dest, int weight)
{
	t_adj_list_node	*node;

	node = (t_adj_list_node*)malloc(sizeof(t_adj_list_node));
	node->dest = dest;
	node->weight = weight;
	node->next = NULL;
	return (node);
}
