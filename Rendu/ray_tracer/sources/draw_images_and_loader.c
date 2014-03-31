/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images_and_loader.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:47:56 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 11:29:17 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

static void		put_pixel(t_env *e, int x, int y)
{
	int			k;

	k = y * e->screens[RAY_TRACE].background.size_line
		+ (x * e->screens[RAY_TRACE].background.bpp);
	if (k >= 0 && k < e->screens[RAY_TRACE].background.max_size)
	{
		e->color.r = e->color.r > 1 ? 1 : e->color.r;
		e->color.g = e->color.g > 1 ? 1 : e->color.g;
		e->color.b = e->color.b > 1 ? 1 : e->color.b;
		e->color.r = e->color.r < 0 ? 0 : e->color.r;
		e->color.g = e->color.g < 0 ? 0 : e->color.g;
		e->color.b = e->color.b < 0 ? 0 : e->color.b;
		e->screens[RAY_TRACE].background.img[k] = (int)(e->color.r * 255);
		e->screens[RAY_TRACE].background.img[k + 1] = (int)(e->color.g * 255);
		e->screens[RAY_TRACE].background.img[k + 2] = (int)(e->color.b * 255);
	}
}

void			draw_pipe(t_env *e, int x)
{
	if (e->progressive_load)
		refresh_load(e, x / (double)WIDTH);
}

void			draw_image(t_env *e)
{
	int			x;
	int			y;

	x = -1;
	compute_up_left(e);
	ft_putstr("\033[31mCreating picture...\033[0m");
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			launch_ray(e, x, y);
			put_pixel(e, x, y);
		}
		if (x % (int)((WIDTH / 50) + 1) == 0)
			draw_pipe(e, x);
	}
	if (e->progressive_load)
		refresh_load(e, 0);
	ft_putstr("\033[32m [OK]\033[0m\n");
	init_img(e->mlx, &e->img_tmp, WIDTH, HEIGHT);
	x = -1;
	while (++x < e->img_tmp.max_size)
		e->img_tmp.img[x] = e->screens[RAY_TRACE].background.img[x];
	e->cur_screen = RAY_TRACE;
}
