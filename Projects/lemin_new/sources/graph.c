/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:22:54 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/15 13:24:00 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// A utility function that creates a graph of V vertices
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
	return (graph);
}

// Adds an edge to an undirected graph
void				add_edge(t_graph *graph, int src, int dest, int weight) //TODO remove weight
{
	t_adj_list_node	*node;

	//TODO check for existing node ?
	// Add an edge from src to dest.  A new node is added to the adjacency
	// list of src.  The node is added at the begining
	node = new_adj_list_node(dest, weight);
	node->next = graph->array[src].head;
	graph->array[src].head = node;
	// Since graph is undirected, add an edge from dest to src also
	node = new_adj_list_node(src, weight);
	node->next = graph->array[dest].head;
	graph->array[dest].head = node;
}

// A utility function to create a new adjacency list node
t_adj_list_node		*new_adj_list_node(int dest, int weight)
{
	t_adj_list_node	*node;

	node = (t_adj_list_node*)malloc(sizeof(t_adj_list_node));
	node->dest = dest;
	node->weight = weight;
	node->next = NULL;
	return (node);
}
