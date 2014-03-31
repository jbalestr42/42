/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 15:22:21 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 05:19:16 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include <unistd.h>
#include "video.h"
#include "ray_tracer.h"

static void		put_pixel_img(t_env *e, t_img *vid, int x, int y)
{
	int			k;

	k = y * vid->size_line
		+ (x * vid->bpp);
	if (k >= 0 && k < vid->max_size)
	{
		e->color.r = e->color.r > 1 ? 1 : e->color.r;
		e->color.g = e->color.g > 1 ? 1 : e->color.g;
		e->color.b = e->color.b > 1 ? 1 : e->color.b;
		e->color.r = e->color.r < 0 ? 0 : e->color.r;
		e->color.g = e->color.g < 0 ? 0 : e->color.g;
		e->color.b = e->color.b < 0 ? 0 : e->color.b;
		vid->img[k] = (int)(e->color.r * 255);
		vid->img[k + 1] = (int)(e->color.g * 255);
		vid->img[k + 2] = (int)(e->color.b * 255);
	}
}

void			draw_pics(t_env *e, t_img *vid)
{
	int			x;
	int			y;

	x = -1;
	compute_up_left(e);
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			launch_ray(e, x, y);
			put_pixel_img(e, vid, x, y);
		}
	}
}

void			change_cam_pos(t_env *e, int i)
{
	double		ang;

	ang = (i * M_PI / 90);
	if (i % (int)((180 / 10) + 1) == 0)
		ft_putstr("\033[31m|\033[0m");
	else if (i % (int)((180 / 50) + 1) == 0)
	{
		ft_putstr("|");
		if (e->progressive_load)
			refresh_load(e, (double)i / 180);
	}
	e->cam.pos.x = 90 * sin(ang);
	e->cam.pos.z = 90 * cos(ang);
}

void			display_video(t_env *e, t_img *vid)
{
	int			i;
	int			j;

	j = -1;
	while (++j < 3)
	{
		i = 0;
		while (i < 180)
		{
			mlx_put_image_to_window(e->mlx, e->win, vid[i].ptr, 0, 0);
			usleep(20000);
			i++;
		}
	}
}

void			create_pics(t_env *e)
{
	int			i;

	i = 0;
	ft_putstr("\033[31mCreating video...\n[\033[0m");
	while (i < 180)
	{
		init_img(e->mlx, &e->vid[i], WIDTH, HEIGHT);
		change_cam_pos(e, i);
		draw_pics(e, &e->vid[i]);
		i++;
	}
	ft_putstr("\033[31m]\033[0m 100%\n");
	e->cur_screen = RAY_TRACE;
	display_video(e, e->vid);
}
