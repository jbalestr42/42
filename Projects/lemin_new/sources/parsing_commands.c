/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 10:13:51 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/15 13:04:48 by jbalestr         ###   ########.fr       */
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

static char	**check_command_start(t_graph *graph, int fd, char **line, int *error_flag)
{
	char	**tmp;

	if (!ft_strcmp(*line, "##start"))
	{
		if (graph->start != NULL)
		{
			*error_flag = 1;
			printf("Found start 2 times");
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
		printf("Command parsing failed\n");
	}
	return (NULL);
}

static char	**check_command_end(t_graph *graph, int fd, char **line, int *error_flag)
{
	char	**tmp;

	if (!ft_strcmp(*line, "##end"))
	{
		if (graph->end != NULL)
		{
			*error_flag = 1;
			printf("Found end 2 times");
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
		printf("Command parsing failed\n");
	}
	return (NULL);
}

char		**check_commands(t_graph *graph, int fd, char **line, int *error_flag)
{
	char	**tmp;

	tmp = check_command_start(graph, fd, line, error_flag);
	if (tmp)
		return (tmp);
	tmp = check_command_end(graph, fd, line, error_flag);
	if (tmp)
		return (tmp);
	else
	{
		*error_flag = 0;
		return (NULL);
	}
	*error_flag = 1;
	return (NULL);
}
