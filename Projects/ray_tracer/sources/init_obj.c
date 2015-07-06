/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:13:22 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 13:44:29 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ray_tracer.h"
#include "obj_file.h"

t_vertices		*new_vertex(t_vertex v)
{
	t_vertices	*new;

	if (!(new = (t_vertices *)malloc(sizeof(t_vertices))))
		return (NULL);
	new->vec = v;
	new->next = NULL;
	return (new);
}

void			push_vertex(t_vertices **begin, t_vertices *new)
{
	t_vertices	*tmp;

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

t_obj			*new_triangle(t_triangle t)
{
	t_obj		*new;

	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
		return (NULL);
	new->triangle = t;
	new->next = NULL;
	return (new);
}

void			push_triangle(t_obj **begin, t_obj *new)
{
	t_obj		*tmp;

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
