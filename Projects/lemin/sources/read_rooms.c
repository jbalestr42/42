/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 13:20:16 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/08 11:39:57 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "libft.h"

static t_room	*new_room(char *name, int x, int y)
{
	t_room		*room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	room->name = ft_strdup(name);
	room->pos.x = x;
	room->pos.y = y;
	room->state = EMPTY;
	room->neighbour = NULL;
	return (room);
}

static int		push_room(t_path **begin, t_room *new)
{
	t_path		*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (0);
	path->room = new;
	path->next = NULL;
	if (!*begin)
		*begin = path;
	else
	{
		path->next = *begin;
		*begin = path;
	}
	return (1);
}

// ajouter la lecture des noms avec des espaces
// ajouter la verif des salles avec coordonnee identique et avec noms identique
static int		valid_room(char *s, t_room **room)
{
	char		**tmp;
	int			x;
	int			y;

	x = 0;
	y = 0;
	tmp = ft_strsplit(s, ' ');
	if (tmp && ft_strlen_tab(tmp) == 3)
	{
		if (tmp[0][0] == 'L' || tmp[0][0] == COMMENT)
			return (ft_free_tab(tmp)); // strerror invalid name
		if (!ft_strequ(tmp[1], "0"))
		{
			if (!(x = valid_nbr(tmp[1], 1)))
				return (ft_free_tab(tmp)); // strerror invalid name
		}
		if (!ft_strequ(tmp[2], "0"))
		{
			if (!(y = valid_nbr(tmp[2], 1)))
				return (ft_free_tab(tmp)); // strerror invalid name
		}
		*room = new_room(tmp[0], x, y);
		ft_free_tab(tmp);
		return (1);
	}
	return (2); // start to read path
}

static int		valid_comment(t_line **line, t_env *e, char *s)
{
	if (ft_strequ(s, START))
	{
		if (e->start)
			return (0);
		next_line(line);
		if (!valid_room((*line)->line, &e->start))
			return (0);
		if (!push_room(&e->rooms, e->start))
			return (0); // error malloc
	}
	else if (ft_strequ(s, END))
	{
		if (e->end)
			return (0);
		next_line(line);
		if (!valid_room((*line)->line, &e->end))
			return (0);
		if (!push_room(&e->rooms, e->end))
			return (0); // error malloc
	}
	return (1);
}

int				read_rooms(t_env *e, t_line **line)
{
	t_room		*room;
	char		*s;
	int			valid;

	while (*line)
	{
		s = (*line)->line;
		if (s[0] == COMMENT)
		{
			if (!valid_comment(line, e, s))
				return (0); // error fail start || end
		}
		else
		{
			if (!(valid = valid_room(s, &room)))
				return (0); // fail room
			if (valid == 2)
				return (1); // start to read path
			if (!push_room(&e->rooms, room))
				return (0); // error malloc
		}
		next_line(line);
	}
	return (0); // error no more line and no path
}
