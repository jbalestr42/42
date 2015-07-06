/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 11:31:37 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/21 15:52:32 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "libft.h"

/*
** s : string to parse
** neg : 1 : allow negative number
*/
int				valid_nbr(char *s, int neg)
{
	int			i;

	i = (neg && s[0] == '-') ? 1 : 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0); // perror
		i++;
	}
	i = ft_atoi(s);
	if (i < 0 && !neg)
		return (0); // perror
	return (i);
}

void			next_line(t_line **line)
{
	t_line		*tmp;

	if (*line)
	{
		tmp = *line;
		ft_putendl((*line)->line);
		*line = (*line)->next;
		ft_strdel(&tmp->line);
		free(tmp);
	}
}

int				check_graph(t_env *e)
{
	if (!e->start || !e->end)
		return (0);
	if (e->nb_ant <= 0)
		return (0);
	if (!e->rooms)
		return (0);
	return (1);
}

int				init_graph(t_env *e)
{
	t_line		*lines;

	lines = NULL;
	if (!(lines = read_std()))
		return (0); // perror
	if (!read_ants(e, &lines))
		return (0); // perror
	if (!read_rooms(e, &lines))
		return (0); // perror
	read_paths(e, &lines);
	if (!check_graph(e))
		return (0);
	if (!init_ants(e))
		return (0);
	// si il reste des ligne, il faut les supprimer et eventuellement les afficher
	/*while (e->rooms)
	{
		ft_putendl(e->rooms->room->name);
		while (e->rooms->room->neighbour)
		{
			ft_putstr("   ");
			ft_putendl(e->rooms->room->neighbour->room->name);
			e->rooms->room->neighbour = e->rooms->room->neighbour->next;
		}
		e->rooms = e->rooms->next;
	}*/
	return (1);
}
