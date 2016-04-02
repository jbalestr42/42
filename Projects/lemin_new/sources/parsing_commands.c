/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 10:13:51 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/15 17:40:20 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "gnl.h"

static char	**check_room(char *line)
{
	char	**tmp;

	if (line)
	{
		tmp = ft_splitwhite(line);
		if (tmp)
		{
			if (ft_strlen_tab(tmp) == 3)
				return (tmp);
			free_split(tmp);
		}
	}
	return (NULL);
}

static char	**check_command_start(t_graph *graph, int fd, char **line)
{
	char	**tmp;

	if (!ft_strcmp(*line, "##start"))
	{
		if (graph->start != NULL)
		{
			ft_putendl("Found start 2 times.");
			return (NULL);
		}
		free(*line);
		*line = NULL;
		get_next_line(fd, line);
		if (!*line)
			return (NULL);
		ft_putendl(*line);
		tmp = check_room(*line);
		if (tmp)
		{
			graph->start = ft_strdup(tmp[0]);
			return (tmp);
		}
	}
	return (NULL);
}

static char	**check_command_end(t_graph *graph, int fd, char **line)
{
	char	**tmp;

	if (!ft_strcmp(*line, "##end"))
	{
		if (graph->end != NULL)
		{
			ft_putendl("Found end 2 times.");
			return (NULL);
		}
		free(*line);
		*line = NULL;
		get_next_line(fd, line);
		if (!*line)
			return (NULL);
		ft_putendl(*line);
		tmp = check_room(*line);
		if (tmp)
		{
			graph->end = ft_strdup(tmp[0]);
			return (tmp);
		}
	}
	return (NULL);
}

char		**check_commands(t_graph *graph, int fd, char **line, int *error_flag)
{
	char	**tmp;

	if (!ft_strcmp(*line, "##start"))
	{
		tmp = check_command_start(graph, fd, line);
		if (tmp)
			return (tmp);
	}
	else if (!ft_strcmp(*line, "##end"))
	{
		tmp = check_command_end(graph, fd, line);
		if (tmp)
			return (tmp);
	}
	*error_flag = 1;
	return (NULL);
}
