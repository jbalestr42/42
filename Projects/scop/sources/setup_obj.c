/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:52:16 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 18:01:32 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void				setup_mesh_vertex(t_obj_data *obj_data,
		t_vertex_list *vertex_list)
{
	float			col[5];
	int				i;
	t_vertex_list	*tmp;

	col[0] = 0.2f;
	col[1] = 0.4f;
	col[2] = 0.6f;
	col[3] = 0.8f;
	col[4] = 1.0f;
	i = obj_data->vertex_count - 1;
	obj_data->obj_vertices = (t_vertex*)malloc(sizeof(t_vertex)
			* obj_data->vertex_count);
	while (i >= 0)
	{
		obj_data->obj_vertices[i] = vertex_list->vertex;
		obj_data->obj_vertices[i].position[3] = 1.0f;
		obj_data->obj_vertices[i].color[0] = col[i % 5];
		obj_data->obj_vertices[i].color[1] = col[i % 5];
		obj_data->obj_vertices[i].color[2] = col[i % 5];
		obj_data->obj_vertices[i].color[3] = 1.0f;
		i--;
		tmp = vertex_list;
		vertex_list = vertex_list->next;
		free(tmp);
	}
}

static float		get_min(float n1, float n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

static float		get_max(float n1, float n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

void				setup_mesh_origin(t_obj_data *obj_data)
{
	float			min[3];
	float			max[3];
	int				i;

	i = -1;
	while (++i < 3)
	{
		min[i] = 99999999.f;
		max[i] = -99999999.f;
		obj_data->origin.v[0] = 0.f;
	}
	i = -1;
	while (++i < obj_data->vertex_count)
	{
		min[0] = get_min(obj_data->vertices[i].position[0], min[0]);
		min[1] = get_min(obj_data->vertices[i].position[1], min[1]);
		min[2] = get_min(obj_data->vertices[i].position[2], min[2]);
		max[0] = get_max(obj_data->vertices[i].position[0], max[0]);
		max[1] = get_max(obj_data->vertices[i].position[1], max[1]);
		max[2] = get_max(obj_data->vertices[i].position[2], max[2]);
	}
	obj_data->origin.v[0] = (-min[0] - max[0]) / 2.f;
	obj_data->origin.v[1] = (-min[1] - max[1]) / 2.f;
	obj_data->origin.v[2] = (-min[2] - max[2]) / 2.f;
}
