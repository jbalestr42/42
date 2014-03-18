/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/18 16:16:09 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/21 13:08:14 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "libft.h"

static int		push_path(t_room *a, t_room *b)
{
	t_path		*path;
	t_path		*tmp;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (0);
	path->room = b;
	path->phero = 0;
	path->next = NULL;
	if (!a->neighbour)
		a->neighbour = path;
	else
	{
		tmp = a->neighbour;
		while (tmp->next)
		{
			if (ft_strequ(tmp->room->name, b->name))
			{
				tmp->room = b;
				return (1);
			}
			tmp = tmp->next;
		}
		tmp->next = path;
	}
	return (1);
}

static t_room	*find_room(t_env *e, char *name)
{
	t_path		*tmp;

	tmp = e->rooms;
	while (tmp)
	{
		if (ft_strequ(tmp->room->name, name))
			return (tmp->room);
		tmp = tmp->next;
	}
	return (NULL);
}

static int		valid_path(t_env *e, char *s, t_room **a, t_room **b)
{
	char		**tmp;

	tmp = ft_strsplit(s, '-');
	if (tmp && ft_strlen_tab(tmp) == 2)
	{
		*a = find_room(e, tmp[0]);
		*b = find_room(e, tmp[1]);
		if (!*a || !*b || *a == *b)
			return (0);
		return (1);
	}
	return (0);
}

// verifier les noms avec espaces
// verifier si le nom existe
// ajouter la verif start et end
int				read_paths(t_env *e, t_line **line)
{
	t_room		*a;
	t_room		*b;
	char		*s;

	a = NULL;
	b = NULL;
	while (*line)
	{
		s = (*line)->line;
		if (s[0] != COMMENT)
		{
			if (!valid_path(e, s, &a, &b))
				return (0); // error
			push_path(a, b);
			push_path(b, a);
		}
		next_line(line);
	}
	return (1);
}
