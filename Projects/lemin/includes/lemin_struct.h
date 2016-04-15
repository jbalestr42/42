/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 10:54:28 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/04 10:21:26 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_STRUCT_H
# define LEMIN_STRUCT_H

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

typedef struct				s_room
{
	int						num;
	char					*name;
	struct s_room			*next;
}							t_room;

typedef struct				s_min_heap_node
{
	int						idx;
	int						dist;
}							t_min_heap_node;

typedef struct				s_min_heap
{
	int						size;
	int						capacity;
	int						*pos;
	t_min_heap_node			**array;
	t_min_heap_node			**array_tmp;
}							t_min_heap;

typedef struct				s_print_data
{
	t_ant					**ants;
	int						*path;
	int						*room_valid;
	int						i;
	int						ant_at_end;
}							t_print_data;

typedef struct				s_parsing_data
{
	char					**tmp;
	char					*line;
	int						err;
	int						ret;
}							t_parsing_data;

typedef struct				s_graph
{
	int						start_idx;
	int						end_idx;
	char					*start;
	char					*end;
	int						ant_count;
	int						room_count;
	int						count;
	t_adj_list				*array;
	char					**room_name;
	t_min_heap				*heap;
}							t_graph;

#endif
