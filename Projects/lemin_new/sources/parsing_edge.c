/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_edge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 16:08:01 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/15 17:04:54 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "gnl.h"

int			find_name(t_graph *graph, char *name)
{
	int		i;

	i = 0;
	while (i < graph->room_count)
	{
		if (!ft_strcmp(graph->room_name[i], name))
			return (i);
		i++;
	}
	return (-1);
}

int			contains_bad_char(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < ft_strlen(line))
	{
		if (line[i] == '-')
			count++;
		if (count > 1)
			return (0);
		i++;
	}
	return (1);
}

int			parse_edge(t_graph *graph, char *line)
{
	char	**tmp;
	int		index1;
	int		index2;

	if (!contains_bad_char(line))
		return (return_print(0, "The edge contains more than one \'-\'"));
	tmp = ft_strsplit(line, '-');
	if (tmp && ft_strlen_tab(tmp) != 2)
		return (return_free_tab(NULL, tmp, 0, "Wrong arguments number"));
	index1 = find_name(graph, tmp[0]);
	index2 = find_name(graph, tmp[1]);
	free_split(tmp);
	if (index1 == -1 || index2 == -1)
		return (return_print(0, "Room name doesn't exist"));
	add_edge(graph, index1, index2, 1);
	return (1);
}

int			read_edges(t_graph *graph, int fd, char **tmp)
{
	char	*line;

	line = NULL;
	if (!parse_edge(graph, tmp[0]))
		return (return_free_tab(NULL, tmp, 0, NULL));
	free_split(tmp);
	while (get_next_line(fd, &line))
	{
		if (line)
		{
			ft_putendl(line);
			if (!ft_strlen(line))
				return (return_free(line, 1, "Empty line"));
			if (line[0] == '#')
			{
				if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
					return (return_free(line, 1, "Command at the wrong place"));
			}
			else
			{
				if (!parse_edge(graph, line))
					return return_free(line, 1, NULL);
			}
			free(line);
		}
	}
	return (1);
}
