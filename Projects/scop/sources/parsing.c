/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:52:48 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/11 10:29:31 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "gnl.h"
#include "parsing.h"

static void			split_indices(char const *s, int *indice_vertex,
		int *indice_texture, int *indice_normal)
{
	char			**tmp;

	tmp = ft_strsplit(s, '/');
	*indice_vertex = 1;
	*indice_texture = 1;
	*indice_normal = 1;
	if (tmp)
	{
		if (ft_strlen_tab(tmp) > 2)
			*indice_normal = atoi(tmp[2]);
		if (ft_strlen_tab(tmp) > 1)
			*indice_texture = atoi(tmp[1]);
		if (ft_strlen_tab(tmp) > 0)
			*indice_vertex = atoi(tmp[0]);
	}
	if (tmp)
		free_split(tmp);
}

static int			read_face(t_face_list **begin, char const *s)
{
	char			**tmp;
	int				count;
	int				i_v[3];
	int				i_t[3];
	int				i_n[3];

	tmp = ft_strsplit(s, ' ');
	count = ft_strlen_tab(tmp);
	if (tmp && count >= 3)
	{
		split_indices(tmp[0], &i_v[0], &i_t[0], &i_n[0]);
		split_indices(tmp[1], &i_v[1], &i_t[1], &i_n[1]);
		split_indices(tmp[2], &i_v[2], &i_t[2], &i_n[2]);
		push_face(begin, i_v, i_t, i_n);
		if (count > 3)
		{
			split_indices(tmp[2], &i_v[1], &i_t[1], &i_n[1]);
			split_indices(tmp[3], &i_v[2], &i_t[2], &i_n[2]);
			push_face(begin, i_v, i_t, i_n);
		}
	}
	if (tmp)
		free_split(tmp);
	return (count == 3 ? 1 : 2);
}

static void			read_line(char *line, t_vertex_list **vertex_list,
		t_obj_data *obj_data, t_uv_list **uv_list)
{
	float			values[3];

	if (line[1] == ' ' || line[1] == '\t')
	{
		read_float(&line[1], values, 3);
		push_vertex(vertex_list, values);
		obj_data->vertex_count++;
	}
	else if (line[1] == 't')
	{
		read_float(&line[2], values, 2);
		push_uv(uv_list, values);
		obj_data->uv_count++;
	}
}

static int			read_mesh(t_obj_data *obj_data, int fd)
{
	char			*line;
	t_vertex_list	*vertex_list;
	t_uv_list		*uv_list;
	t_face_list		*face_list;

	line = NULL;
	vertex_list = NULL;
	uv_list = NULL;
	face_list = NULL;
	while (get_next_line(fd, &line))
	{
		if (line)
		{
			if (line[0] == 'v')
				read_line(line, &vertex_list, obj_data, &uv_list);
			else if (line[0] == 'f')
				obj_data->face_count += read_face(&face_list, &line[1]);
			free(line);
		}
	}
	setup_mesh_vertex(obj_data, vertex_list);
	setup_mesh_uv(obj_data, uv_list);
	setup_mesh_faces(obj_data, face_list);
	setup_mesh_origin(obj_data);
	return (1);
}

int					load_mesh(t_obj_data *obj_data, char const *filename)
{
	int				fd;

	if (!is_valid_name(filename))
		return (0);
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	obj_data->obj_vertices = NULL;
	obj_data->vertices = NULL;
	obj_data->obj_uvs = NULL;
	obj_data->indices = NULL;
	obj_data->vertex_count = 0;
	obj_data->face_count = 0;
	obj_data->uv_count = 0;
	obj_data->indice_count = 0;
	if (!read_mesh(obj_data, fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
