/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 10:54:28 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/14 17:00:42 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_STRUCT_HPP
# define LEMIN_STRUCT_HPP

typedef struct				s_ant
{
	int						num;
	int						room;
}							t_ant;

typedef struct				s_adj_list_node
{
	int						dest;
	int						weight;
	struct s_adj_list_node	*next;
}							t_adj_list_node;

typedef struct				s_adj_list
{
	struct s_adj_list_node	*head;
}							t_adj_list;

typedef struct				s_graph
{
	char					*start;
	char					*end;
	int						ant_count;
	int						room_count;
	int						V;
	t_adj_list				*array;
	char					**room_name;
}							t_graph;

typedef struct				s_room
{
	int						num;
	char					*name;
	struct s_room			*next;
}							t_room;

typedef struct				s_min_heap_node
{
	int						v;
	int						dist;
}							t_min_heap_node;

typedef struct				s_min_heap
{
	int						size;
	int						capacity;
	int						*pos;
	t_min_heap_node			**array;
}							t_min_heap;

#endif
