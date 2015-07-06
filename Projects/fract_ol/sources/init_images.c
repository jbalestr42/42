/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 15:09:26 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/10 13:25:16 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

static t_img	init_image(void *mlx, char *path, int width, int height)
{
	t_img		img;

	img.width = width;
	img.height = height;
	img.ptr = mlx_xpm_file_to_image(mlx, path, &width, &height);
	img.img = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	img.bpp /= 8;
	img.max_size = img.size_line * height + img.bpp * width;
	return (img);
}

void			init_images(t_env *e)
{
	e->pals[0] = init_image(e->mlx, T_PAL, 256, 1);
	e->pals[1] = init_image(e->mlx, T_PAL1, 512, 1);
	e->pals[2] = init_image(e->mlx, T_PAL2, 512, 1);
	e->pals[3] = init_image(e->mlx, T_PAL3, 512, 1);
	e->pals[4] = init_image(e->mlx, T_PAL4, 512, 1);
	e->pals[5] = init_image(e->mlx, T_PAL5, 512, 1);
	e->pals[6] = init_image(e->mlx, T_PAL6, 512, 1);
}

void			ft_envdel(t_env *e)
{
	int			i;

	if (!e)
		return ;
	if (e->screen.ptr)
		mlx_destroy_image(e->mlx, e->screen.ptr);
	i = -1;
	while (++i < NB_PAL)
		mlx_destroy_image(e->mlx, e->pals[i].ptr);
	if (e->mlx)
		free(e->mlx);
	if (e->win)
		free(e->win);
	free(e);
	exit(0);
}

void			init_var(t_env *e)
{
	e->offset_zoom_x = 0.f;
	e->offset_zoom_y = 0.f;
	e->offset_x = 0.f;
	e->offset_y = 0.f;
	e->zoom = 1.f;
	e->click_pos_x = 0;
	e->click_pos_y = 0;
	e->move_pos_x = 0;
	e->move_pos_y = 0;
	e->c0x = 1.5 * (-HALF_WIDTH) / (e->zoom * HALF_WIDTH);
	e->c0y = (-HALF_HEIGHT) / (e->zoom * HALF_HEIGHT);
	e->zoom_width = e->zoom * (double)HALF_WIDTH;
	e->zoom_height = e->zoom * (double)HALF_HEIGHT;
	e->julia_cx = -0.8;
	e->julia_cy = 0.3;
}
