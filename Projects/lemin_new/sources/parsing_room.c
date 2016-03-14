/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:40:21 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/14 10:45:10 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "gnl.h"

static int	read_room(t_room **rooms, char *line, char ***tmp)
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
			return return_free_tab(line, *tmp, 0, "Wrong room format");
		free_split(*tmp);
	}
	return return_free(line, 0, "Wrong room format");
}

static int	check_error(t_graph *graph, t_room **rooms)
{
	if (!*rooms)
		return (return_print(0, "No room found"));
	if (!create_rooms(graph, *rooms))
		return (return_print(0, "Not enough memory to allocate the rooms"));
	if (!(graph)->start || !(graph)->end)
		return (return_print(0, "No start/end room"));
	return (1);
}

int			read_rooms(t_graph *graph, t_room **rooms, int fd)
{
	char	**tmp;
	char	*line;
	int		error_flag;
	int		ret;

	error_flag = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		if (line)
		{
			if (!ft_strlen(line))
				return (return_free(line, 0, "Empty line"));
			if (line[0] == '#')
			{
				tmp = check_commands(graph, fd, &line, &error_flag);
				if (tmp)
				{
					parse_room(rooms, tmp);
					free_split(tmp);
				}
				else if (error_flag)
					return (return_free(line, 0, "Wrong room format after command line"));
			}
			else
			{
				ret = read_room(rooms, line, &tmp);
				if (ret == 1)
					break;
				else if (ret == 0)
					return (0);
			}
			free(line);
		}
		else
			return (return_print(0, "Empty line"));
	}
	if (!check_error(graph, rooms))
		return (0);
	return (read_edges(graph, fd, tmp));
}
