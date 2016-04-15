/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:40:21 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/04 09:58:37 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "gnl.h"

static int			read_room(t_room **rooms, char *line, char ***tmp)
{
	*tmp = ft_splitwhite(line);
	if (*tmp)
	{
		if (ft_strlen_tab(*tmp) == 1)
		{
			free(line);
			return (1);
		}
		else if (ft_strlen_tab(*tmp) == 3)
		{
			if (!parse_room(rooms, *tmp))
				return (return_free_tab(line, *tmp, 0, NULL));
			return (-1);
		}
		else
			return (return_free_tab(line, *tmp, 0, "Wrong room format"));
		free_split(*tmp);
	}
	return (return_free(line, 0, "Wrong room format"));
}

static int			check_error(t_graph *graph, t_room **rooms)
{
	if (!*rooms)
		return (return_print(0, "No room found"));
	if (!create_rooms(graph, *rooms))
		return (return_print(0, "Not enough memory to allocate the rooms"));
	if (!(graph)->start || !(graph)->end)
		return (return_print(0, "No start/end room"));
	graph->start_idx = find_name(graph, graph->start);
	graph->end_idx = find_name(graph, graph->end);
	return (1);
}

static void			init_data(t_parsing_data *data)
{
	data->err = 0;
	data->line = NULL;
	data->tmp = NULL;
}

static int			conditions(t_parsing_data *d, int fd, t_room **rooms,
		t_graph *graph)
{
	if (!ft_strlen(d->line))
		return (return_free(d->line, 0, "Empty line"));
	if (d->line[0] == '#')
	{
		d->tmp = check_commands(graph, fd, &d->line, &d->err);
		if (d->tmp)
		{
			parse_room(rooms, d->tmp);
			free_split(d->tmp);
			d->tmp = NULL;
		}
		if (d->err)
			return (return_free(d->line, 0,
						"Wrong room format after command line"));
	}
	else
	{
		d->ret = read_room(rooms, d->line, &d->tmp);
		if (d->ret == 1)
			return (2);
		else if (d->ret == 0)
			return (0);
		free_split(d->tmp);
	}
	return (1);
}

int					read_rooms(t_graph *graph, t_room **rooms, int fd)
{
	t_parsing_data	d;
	int				ret;

	init_data(&d);
	while (get_next_line(fd, &d.line))
	{
		if (d.line)
		{
			ft_putendl(d.line);
			ret = conditions(&d, fd, rooms, graph);
			if (!ret)
				return (0);
			else if (ret == 2)
				break ;
			free(d.line);
		}
		else
			return (return_print(0, "Empty line"));
	}
	if (!check_error(graph, rooms))
		return (0);
	if (!d.tmp)
		return (return_print(0, "No edge found"));
	return (read_edges(graph, fd, d.tmp));
}
