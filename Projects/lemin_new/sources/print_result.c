/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:01:09 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/15 13:58:15 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_ant	**get_ants(t_graph *graph, int count)
{
	t_ant	**ants;
	int		i;

	ants = (t_ant**)malloc(sizeof(t_ant*) * graph->ant_count);
	i = 0;
	while (i < graph->ant_count)
	{
		ants[i] = (t_ant*)malloc(sizeof(t_ant));
		ants[i]->num = i + 1;
		ants[i]->room = count - 1;
		i++;
	}
	return (ants);
}

static int	*get_path(int *parents, int *size, int src, int dest)
{
	int		*path;
	int		count;
	int		u;

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

static int	is_valid_path(int *parents, int src, int dest)
{
	int		u;
	int		valid;

	u = dest;
	valid = 0;
	while (u != -1)
	{
		if (u == src)
		{
			valid = 1;
			break;
		}
		u = parents[u];
	}
	if (valid)
		return (1);
	return (0);
}

void		ant_stuff(t_graph *graph, int *parents, int src, int dest)
{
	t_ant	**ants;
	int		i;
	int		count;
	int		*path;
	int		room_valid[graph->room_count];

	if (!is_valid_path(parents, src, dest))
	{
		ft_putendl("ERROR");
		return ;
	}
	path = get_path(parents, &graph->room_count, src, dest);
	count = graph->room_count;
	ants = get_ants(graph, count);
	i = 0;
	while (i < graph->room_count)
		room_valid[i++] = 0;
	room_valid[count - 1] = 1;

	int ant_at_end = 0;
	while (ant_at_end != graph->ant_count)
	{
		i = ant_at_end;
		printf("\n");
		while (i < graph->ant_count)
		{
			if (ants[i]->room == 0)
			{
				ant_at_end++;
				room_valid[ants[i]->room] = 0;
			}
			else if (ants[i]->room - 1 >= 0 && room_valid[ants[i]->room - 1] == 0)
			{
				room_valid[ants[i]->room - 1] = 1;
				room_valid[ants[i]->room] = 0;
				ants[i]->room--;
				printf("L%i-%s ", ants[i]->num, graph->room_name[path[ants[i]->room]]);
			}
			i++;
		}
	}
	destroy_result(ants, graph->ant_count, path);
}
