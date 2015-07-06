/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:18:14 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/21 16:05:14 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "libft.h"

static t_ant	*new_ant(t_env *e, int num)
{
	t_ant		*ant;

	if (!(ant = (t_ant *)malloc(sizeof(t_ant))))
		return (NULL);
	ant->num = num;
	ant->displayed = 0;
	ant->cur = e->start;
	ant->path = NULL;
	return (ant);
}

int				init_ants(t_env *e)
{
	int			i;

	if (!(e->ants = (t_ant **)malloc(sizeof(t_ant *) * e->nb_ant)))
		return (0);
	i = -1;
	while (++i < e->nb_ant)
	{
		if (!(e->ants[i] = new_ant(e, i + 1)))
			return (0);
	}
	return (1);
}

int				read_ants(t_env *e, t_line **line)
{
	char		*s;

	while (line)
	{
		s = (*line)->line;
		if (s[0] == COMMENT)
		{
			if (ft_strequ(s, START) || ft_strequ(s, END))
				return (0); // perror
		}
		else
		{
			if (!(e->nb_ant = valid_nbr(s, 0)))
				return (0); // perror
			next_line(line);
			return (1);
		}
		next_line(line);
	}
	return (0); // strerror
}
