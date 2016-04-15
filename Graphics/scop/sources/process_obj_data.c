/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_obj_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:35:11 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 18:36:25 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void			display_info(t_obj_data *obj_data)
{
	ft_putstr("Number of faces : ");
	ft_putnbr(obj_data->face_count);
	ft_putendl("");
	ft_putstr("Number of vertices in the model : ");
	ft_putnbr(obj_data->indice_count);
	ft_putendl("");
	ft_putstr("Number of vertices loaded in memory : ");
	ft_putnbr(obj_data->vertex_count);
	ft_putendl("");
	ft_putstr("Memory usage : ");
	ft_putnbr(obj_data->vertex_count * sizeof(t_vertex));
	ft_putendl("B");
	ft_putstr("Memory optimization : ");
	ft_putnbr((obj_data->indice_count - obj_data->vertex_count)
			* sizeof(t_vertex));
	ft_putendl("B");
}

static void			process_sub_data(t_obj_data *o, t_index *i,
		t_face_list *f, int *ids)
{
	o->vertices[i->count] = o->obj_vertices[f->face.indice_vertex[i->j] - 1];
	o->vertices[i->count].uv[0] =
		o->obj_uvs[f->face.indice_texture[i->j] - 1].position[0];
	o->vertices[i->count].uv[1] =
		o->obj_uvs[f->face.indice_texture[i->j] - 1].position[1];
	ids[i->index] = i->count++;
}

static int			process_data(t_obj_data *o, int u, t_face_list *f,
		int *ids)
{
	t_index			i;

	i.count = 0;
	i.i = -1;
	while (++i.i < o->face_count)
	{
		i.j = 0;
		while (i.j < 3)
		{
			i.index = (f->face.indice_vertex[i.j] - 1)
				* u + f->face.indice_texture[i.j] - 1;
			if (ids[i.index] == -1)
			{
				process_sub_data(o, &i, f, ids);
			}
			o->indices[i.i * 3 + i.j++] = ids[i.index];
		}
		i.tmp = f;
		f = f->next;
		free(i.tmp);
	}
	return (i.count);
}

void				setup_mesh_faces(t_obj_data *obj_data,
		t_face_list *face_list)
{
	int				i;
	int				*ids;
	int				uv_count;

	i = 0;
	obj_data->indice_count = obj_data->face_count * 3;
	obj_data->indices = (GLushort*)malloc(sizeof(GLushort)
			* obj_data->indice_count);
	obj_data->vertices = (t_vertex*)malloc(sizeof(t_vertex)
			* obj_data->indice_count);
	uv_count = obj_data->uv_count > 0 ? obj_data->uv_count : 1;
	ids = (int*)malloc(sizeof(int) * obj_data->vertex_count * uv_count);
	while (i < obj_data->vertex_count * uv_count)
		ids[i++] = -1;
	obj_data->vertex_count = process_data(obj_data, uv_count, face_list, ids);
	free(ids);
	display_info(obj_data);
}

void				setup_mesh_uv(t_obj_data *obj_data, t_uv_list *uv_list)
{
	int				i;
	t_uv_list		*tmp;

	i = obj_data->uv_count - 1;
	obj_data->obj_uvs = (t_uv*)malloc(sizeof(t_uv) * obj_data->uv_count);
	while (i >= 0)
	{
		obj_data->obj_uvs[i] = uv_list->uv;
		i--;
		tmp = uv_list;
		uv_list = uv_list->next;
		free(tmp);
	}
}
