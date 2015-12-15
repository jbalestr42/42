#include <fcntl.h>
#include <unistd.h>
#include "gnl.h"
#include "parsing.h"

static void			read_float(char const *s, float *values, int nb_values)
{
	char			**tmp;
	int				i;

	i = 0;
	tmp = ft_strsplit(s, ' ');
	if (tmp && ft_strlen_tab(tmp) >= nb_values)
	{
		while (i < nb_values)
		{
			values[i] = atof(tmp[i]);
			i++;
		}
	}
	if (tmp)
		free_split(tmp);
}

static void			split_indices(char const *s, int *indice_vertex, int *indice_texture, int *indice_normal)
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
	int				indice_vertex[3];
	int				indice_texture[3];
	int				indice_normal[3];

	tmp = ft_strsplit(s, ' ');
	count = ft_strlen_tab(tmp);
	if (tmp && count >= 3)
	{
		split_indices(tmp[0], &indice_vertex[0], &indice_texture[0], &indice_normal[0]);
		split_indices(tmp[1], &indice_vertex[1], &indice_texture[1], &indice_normal[1]);
		split_indices(tmp[2], &indice_vertex[2], &indice_texture[2], &indice_normal[2]);
		push_face(begin, indice_vertex, indice_texture, indice_normal);
		if (count > 3)
		{
			//split_indices(tmp[0], &indice_vertex[0], &indice_texture[0], &indice_normal[0]);
			split_indices(tmp[2], &indice_vertex[1], &indice_texture[1], &indice_normal[1]);
			split_indices(tmp[3], &indice_vertex[2], &indice_texture[2], &indice_normal[2]);
			push_face(begin, indice_vertex, indice_texture, indice_normal);
		}
	}
	if (tmp)
		free_split(tmp);
	return (count == 3 ? 1 : 2);
}

static int			read_mesh(t_obj_data *obj_data, int fd)
{
	float			values[3];
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
			{
				if (line[1] == ' ' || line[1] == '\t')
				{
					read_float(&line[1], values, 3);
					push_vertex(&vertex_list, values);
					obj_data->vertex_count++;
				}
				else if (line[1] == 't')
				{
					read_float(&line[2], values, 2);
					push_uv(&uv_list, values);
					obj_data->uv_count++;
				}
			}
			else if (line[0] == 'f')
			{
				obj_data->face_count += read_face(&face_list, &line[1]);
			}
			free(line);
		}
	}
	setup_mesh_vertex(obj_data, vertex_list);
	setup_mesh_uv(obj_data, uv_list);
	setup_mesh_faces(obj_data, face_list);
	setup_mesh_origin(obj_data);
	return (1);
}

int				load_mesh(t_obj_data *obj_data, char const *filename)
{
	int			fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (0);
	//set to null
	obj_data->vertex_count = 0;
	obj_data->face_count = 0;
	obj_data->uv_count = 0;
	if (!read_mesh(obj_data, fd))
	{
		close(fd);
		return (0);
	}
	//close(fd);
	return (1);
}
