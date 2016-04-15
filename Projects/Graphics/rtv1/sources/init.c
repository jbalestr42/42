/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 10:42:29 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 13:52:03 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include "ray_tracer.h"

int				ft_strlen(char *s)
{
	int			len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void			ft_error(int b_exit, t_env *e, char *str)
{
	del_env(e);
	if (str)
		write(2, str, ft_strlen(str));
	if (b_exit)
	{
		write(2, "Exit.\n", 6);
		exit(1);
	}
}

t_vec			init_vec(double x, double y, double z)
{
	t_vec		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

void			del_env(t_env *e)
{
	if (e)
	{
		if (e->lights)
			free(e->lights);
		if (e->objects)
			free(e->objects);
		if (e->mlx)
			free(e->mlx);
		if (e->win)
			free(e->win);
		(void)e;
	}
}

t_env			*init_env(char *path)
{
	t_env		*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		ft_error(1, NULL, "Not enough memory.\n");
	if (!(e->mlx = mlx_init()))
		ft_error(1, e, "Mlx fail init.\n");
	if (!(e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, NAME)))
		ft_error(1, e, "Win fail init.\n");
	if (!init_scene(e, path))
		ft_error(1, e, "Wrong file format.\n");
	e->x_ratio = 0.5 / (double)WIDTH;
	e->y_ratio = 0.35 / (double)HEIGHT;
	init_events(e);
	init_types(e);
	init_screen(e->mlx, &e->screen, WIDTH, HEIGHT);
	return (e);
}
