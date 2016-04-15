/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:10:12 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/10 13:47:58 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

static void		init_fractal_fun(t_env *e)
{
	e->fractal_fun[0] = &julia;
	e->fractal_fun[1] = &julia_bof60;
	e->fractal_fun[2] = &julia_bof61;
	e->fractal_fun[3] = &julia_broken;
	e->fractal_fun[4] = &julia_tunnel;
	e->fractal_fun[5] = &mandelbrot;
	e->fractal_fun[6] = &mandelbrot_bof60;
	e->fractal_fun[7] = &mandelbrot_bof61;
	e->fractal_fun[8] = &mandelbrot_broken;
	e->fractal_fun[9] = &mandelbrot_tunnel;
	e->fractal_fun[10] = &burning_ship;
	e->fractal_fun[11] = &newton;
}

static void		init_screen(t_img *img, void *mlx, int width, int height)
{
	img->ptr = mlx_new_image(mlx, width, height);
	img->img = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line,
			&img->endian);
	img->bpp /= 8;
	img->max_size = img->size_line * height + img->bpp * width;
}

void			init_julia(t_env *e, int x, int y)
{
	e->u.cx = e->julia_cx;
	e->u.cy = e->julia_cy;
	e->u.zx = 1.6 * (x - HALF_WIDTH) / (e->zoom_width) + e->offset_x;
	e->u.zy = 1.2 * (y - HALF_HEIGHT) / (e->zoom_height) + e->offset_y;
	e->u.i = 1;
	e->u.cld = 4.0;
	e->u.cln = 0;
	e->u.last_iter = 0;
}

void			init_mandelbrot(t_env *e, int x, int y)
{
	e->u.cx = 1.6 * (x - HALF_WIDTH) / (e->zoom * HALF_WIDTH);
	e->u.cx += e->offset_x - 0.5 + e->offset_zoom_x / 2.0;
	e->u.cy = 1.1 * (y - HALF_HEIGHT) / (e->zoom * HALF_HEIGHT);
	e->u.cy += e->offset_y + e->offset_zoom_y / 2.0;
	e->u.zx = e->u.cx;
	e->u.zy = e->u.cy;
	e->u.i = 0;
	e->u.cld = 4.0;
	e->u.cln = 0;
	e->u.last_iter = 0;
}

t_env			*ft_envnew(void)
{
	t_env		*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, NAME);
	init_screen(&e->screen, e->mlx, WIDTH, HEIGHT);
	init_images(e);
	init_fractal_fun(e);
	init_var(e);
	e->current_fractal = 0;
	e->current_pal = 0;
	return (e);
}
