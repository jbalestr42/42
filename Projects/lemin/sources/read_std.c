/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_std.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 10:21:12 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/18 13:21:09 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "gnl.h"
#include "libft.h"

static t_line	*new_line(char *s)
{
	t_line		*line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return (NULL); // perror
	line->line = s;
	line->next = NULL;
	return (line);
}

static void		push_line(t_line **begin, t_line *new)
{
	t_line		*tmp;

	if (!new)
		return ;
	if (!*begin)
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_line			*read_std(void)
{
	char		*line;
	t_line		*lines;

	line = NULL;
	lines = NULL;
	while (get_next_line(STD_IN, &line))
	{
		if (line)
		{
			push_line(&lines, new_line(line));
			line = NULL;
		}
	}
	return (lines);
}
