/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:00 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 13:52:02 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ray_tracer.h"
#include "gnl.h"

static void		read_pos_dir(t_env *e, t_vec *p, char *s)
{
	char		**tmp;

	tmp = ft_strsplit(s, ' ');
	if (tmp && ft_strlen_tab(tmp) == 3)
	{
		p->x = ft_atoi(tmp[0]);
		p->y = ft_atoi(tmp[1]);
		p->z = ft_atoi(tmp[2]);
		free_split(tmp);
	}
	else
		ft_error(1, e, "Camera wrong format.\n");
}

static void		compute_pos_plan(t_env *e)
{
	t_vec		up_vec;
	t_vec		right_vec;
	t_vec		res;
	t_vec		dir;

	mul_vec_val(&right_vec, &e->cam.right, 0.5 / 2.0);
	mul_vec_val(&up_vec, &e->cam.down, 0.35 / 2.0);
	mul_vec_val(&dir, &e->cam.dir, 1.0);
	sub_vec(&res, &up_vec, &right_vec);
	add_vec(&res, &res, &dir);
	add_vec(&e->pos_plan, &res, &e->cam.ori);
}

static int		read_objects(t_env *e, int fd)
{
	char		*line;
	int			i;

	i = -1;
	line = NULL;
	if (get_next_line(fd, &line))
		e->nb_object = ft_atoi(line);
	if (!(e->objects = (t_object *)malloc(sizeof(t_object) * e->nb_object)))
		return (-1);
	while (++i < e->nb_object && get_next_line(fd, &line))
	{
		if (line[0] == '0')
			e->objects[i] = read_sphere(e, &line[2]);
		else if (line[0] == '1')
			e->objects[i] = read_plan(e, &line[2]);
		else if (line[0] == '2')
			e->objects[i] = read_cylinder(e, &line[2]);
		else if (line[0] == '3')
			e->objects[i] = read_cone(e, &line[2]);
		else
			ft_error(0, e, "Primitive unknow.\n");
	}
	return (1);
}

static int		read_file(t_env *e, int fd)
{
	char		*line;
	int			i;

	i = -1;
	line = NULL;
	if (get_next_line(fd, &line))
		read_pos_dir(e, &e->cam.ori, line);
	if (get_next_line(fd, &line))
		read_pos_dir(e, &e->cam.dir, line);
	normalize(&e->cam.dir);
	e->cam.down = init_vec(0, 1, 0);
	mul_vec(&e->cam.right, &e->cam.down, &e->cam.dir);
	normalize(&e->cam.right);
	compute_pos_plan(e);
	if (get_next_line(fd, &line))
		e->nb_light = ft_atoi(line);
	if (!(e->lights = (t_light *)malloc(sizeof(t_light) * e->nb_light)))
		return (-1);
	while (++i < e->nb_light && get_next_line(fd, &line))
		e->lights[i] = read_light(e, line);
	return (read_objects(e, fd));
}

int				init_scene(t_env *e, char *path)
{
	int			fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		ft_error(1, e, "Can't open file.\n");
	if (!read_file(e, fd))
	{
		close(fd);
		ft_error(1, e, "Can't read file.\n");
	}
	close(fd);
	return (1);
}
