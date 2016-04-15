/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:01:09 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/02 18:56:28 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_ant		**get_ants(t_graph *graph, int count, int *room_valid)
{
	t_ant			**ants;
	int				i;

	ants = (t_ant**)malloc(sizeof(t_ant*) * graph->ant_count);
	i = 0;
	while (i < graph->ant_count)
	{
		ants[i] = (t_ant*)malloc(sizeof(t_ant));
		ants[i]->num = i + 1;
		ants[i]->room = count - 1;
		i++;
	}
	i = 0;
	while (i < graph->room_count)
		room_valid[i++] = 0;
	room_valid[graph->room_count - 1] = 1;
	return (ants);
}

static int			*get_path(int *parents, int *size, int src, int dest)
{
	int				*path;
	int				count;
	int				u;

	u = dest;
	path = (int*)malloc(sizeof(int) * *size);
	count = 0;
	path[count++] = dest;
	while (u != src && u != -1)
	{
		u = parents[u];
		path[count++] = u;
	}
	*size = count;
	return (path);
}

static int			is_valid_path(int *parents, int src, int dest)
{
	int				u;
	int				valid;

	u = dest;
	valid = 0;
	while (u != -1)
	{
		if (u == src)
		{
			valid = 1;
			break ;
		}
		u = parents[u];
	}
	if (valid)
		return (1);
	return (0);
}

static void			init_data(t_print_data *data, t_graph *graph)
{
	data->i = 0;
	data->ant_at_end = 0;
	data->room_valid = (int*)malloc(sizeof(int) * graph->room_count);
	data->ants = get_ants(graph, graph->room_count, data->room_valid);
}

int					ant_stuff(t_graph *graph, int *parents, int src, int dest)
{
	t_print_data	d;

	if (!is_valid_path(parents, src, dest))
		return (return_print(0, "ERROR"));
	d.path = get_path(parents, &graph->room_count, src, dest);
	init_data(&d, graph);
	while (d.ant_at_end != graph->ant_count)
	{
		d.i = d.ant_at_end;
		ft_putendl("");
		loop_ants(&d, graph);
	}
	destroy_result(d.ants, graph->ant_count, d.path, d.room_valid);
	return (1);
}
