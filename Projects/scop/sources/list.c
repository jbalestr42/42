/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:41:11 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 18:41:58 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_face_list			*push_face(t_face_list **begin,
		int *indice_vertex, int *indice_texture, int *indice_normal)
{
	t_face_list		*new;
	int				i;

	new = (t_face_list*)malloc(sizeof(t_face_list));
	if (!new)
		return (NULL);
	i = 0;
	while (i < 3)
	{
		new->face.indice_vertex[i] = indice_vertex[i];
		new->face.indice_texture[i] = indice_texture[i];
		new->face.indice_normal[i] = indice_normal[i];
		i++;
	}
	new->next = NULL;
	if (*begin == NULL)
		*begin = new;
	else
	{
		new->next = *begin;
		*begin = new;
	}
	return (new);
}

t_vertex_list		*push_vertex(t_vertex_list **begin, float *values)
{
	t_vertex_list	*new;
	int				i;

	i = 0;
	new = (t_vertex_list*)malloc(sizeof(t_vertex_list));
	if (!new)
		return (NULL);
	while (i < 4)
	{
		new->vertex.position[i] = values[i];
		i++;
	}
	new->next = NULL;
	if (*begin == NULL)
		*begin = new;
	else
	{
		new->next = *begin;
		*begin = new;
	}
	return (new);
}

t_uv_list			*push_uv(t_uv_list **begin, float *values)
{
	t_uv_list		*new;

	new = (t_uv_list*)malloc(sizeof(t_uv_list));
	if (!new)
		return (NULL);
	new->uv.position[0] = values[0];
	new->uv.position[1] = values[1];
	new->next = NULL;
	if (*begin == NULL)
		*begin = new;
	else
	{
		new->next = *begin;
		*begin = new;
	}
	return (new);
}
