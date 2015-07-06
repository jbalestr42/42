/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:17:20 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 17:14:47 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "ray_tracer.h"
#include "gnl.h"
#include "obj_file.h"
#include "parser.h"

static void		read_vertex(t_vertices **begin, char *s)
{
	t_vertex	vec;
	char		**tmp;

	tmp = ft_strsplit(s, ' ');
	if (tmp && ft_strlen_tab(tmp) == 3)
	{
		vec.x = ft_atod(tmp[0]);
		vec.y = ft_atod(tmp[1]);
		vec.z = ft_atod(tmp[2]);
		push_vertex(begin, new_vertex(vec));
		free_split(tmp);
	}
	else if (tmp)
		free_split(tmp);
}

static void		find_vec(t_vertices *vertices, int index, t_vertex *vec)
{
	t_vertices	*tmp;
	int			i;

	tmp = vertices;
	i = 1;
	while (tmp)
	{
		if (i == index)
		{
			vec->x = tmp->vec.x;
			vec->y = tmp->vec.y;
			vec->z = tmp->vec.z;
			return ;
		}
		tmp = tmp->next;
		i++;
	}
}

static int		read_face(t_obj **begin, t_vertices *vertices, char *s)
{
	t_triangle	tri;
	char		**tmp;
	int			i[3];

	tmp = ft_strsplit(s, ' ');
	if (tmp && ft_strlen_tab(tmp) == 3)
	{
		i[0] = ft_atoi(tmp[0]);
		i[1] = ft_atoi(tmp[1]);
		i[2] = ft_atoi(tmp[2]);
		find_vec(vertices, i[0], &tri.v1);
		find_vec(vertices, i[1], &tri.v2);
		find_vec(vertices, i[2], &tri.v3);
		tri.v2 = sub(tri.v2, tri.v1);
		tri.v3 = sub(tri.v3, tri.v1);
		tri.normal = normalize(cross(tri.v2, tri.v3));
		push_triangle(begin, new_triangle(tri));
		free_split(tmp);
	}
	else if (tmp)
		free_split(tmp);
	return (1);
}

static int		read_obj(t_env *e, int fd)
{
	char		*line;
	t_vertices	*vertices;
	t_obj		*triangles;
	int			nb_face;

	nb_face = 0;
	line = NULL;
	vertices = NULL;
	triangles = NULL;
	while (get_next_line(fd, &line))
	{
		if (line)
		{
			if (line[0] == 'v' && (line[1] == ' ' || line[1] == '\t'))
				read_vertex(&vertices, &line[1]);
			else if (line[0] == 'f')
				nb_face += read_face(&triangles, vertices, &line[1]);
			free(line);
		}
	}
	e->obj = triangles;
	e->nb_obj = nb_face;
	return (1);
}

int				open_obj(t_env *e, char *path)
{
	int			fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	if (!read_obj(e, fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
