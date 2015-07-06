/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:03:52 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/22 16:41:59 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "gnl.h"
#include <stdlib.h>

static int		read_first_line(t_data *d, char *line)
{
	if (!line)
		return (FAIL);
	if (line[10] == '1')
		d->p_char = P1_CHAR;
	else
		d->p_char = P2_CHAR;
	return (SUCCESS);
}

static int		read_size(t_surface *s, char *line)
{
	char	**split;

	if (!line)
		return (FAIL);
	split = ft_strsplit(line, ' ');
	if (!split)
		return (FAIL);
	s->height = ft_atoi(split[1]);
	s->width = ft_atoi(split[2]);
	//free_tab(split);
	return (SUCCESS);
}

static int		read_surface_size(t_surface *s)
{
	char	*line;

	line = NULL;
	if (get_next_line(STD_IN, &line))
	{
		if (!read_size(s, line))
			return (ERR_SM);
	}
	if (!(s->tab = (char **)malloc(sizeof(char *) * s->height)))
		return (ERR_MAL);
	return (SUCCESS);
}

static void		read_surface(t_surface *s, int index)
{
	char	*line;
	int		i;

	i = -1;
	line = NULL;
	while (++i < s->height)
	{
		get_next_line(STD_IN, &line);
		if (line)
			s->tab[i] = ft_strdup(&line[index]);
	}
}

int			ft_read(void)
{
	t_data	d;
	char	*line;

	line = NULL;
	if (get_next_line(STD_IN, &line))
	{
		if (!read_first_line(&d, line))
			return (ERR_FL);
	}
	while (42)
	{
		if (!read_surface_size(&(d.map)))
			return (ERR_FL);
		get_next_line(STD_IN, &line);
		ft_strdel(&line);
		// free la piece si elle existe
		read_surface(&(d.map), 4);
		if (!read_surface_size(&(d.piece)))
			return (ERR_FL);
		read_surface(&(d.piece), 0);
		filler(&d);
	}
	// free map
	return (SUCCESS);
}
