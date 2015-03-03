/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:10:12 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/03 14:01:00 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

static void	init_screen(t_img *img, void *mlx, int width, int height)
{
	img->ptr = mlx_new_image(mlx, width, height);
	img->img = mlx_get_data_addr(img->ptr, &img->bpp, &img->size_line, &img->endian);
	img->bpp /= 8;
	img->max_size = img->size_line * height + img->bpp * width;
}

#include <stdio.h>
static t_img	init_image(void *mlx, char *path, int width, int height)
{
	t_img	img;

	img.width = width;
	img.height = height;
	img.ptr = mlx_xpm_file_to_image(mlx, path, &width, &height);
	img.img = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	img.bpp /= 8;
	img.max_size = img.size_line * height + img.bpp * width;
	printf("%d %d %d %d\n", img.bpp, img.size_line, img.max_size, img.endian);
	return (img);
}

void			ft_envdel(t_env *e)
{
	if (!e)
		return ;
	if (e->screen.ptr)
		mlx_destroy_image(e->mlx, e->screen.ptr);
	if (e->mlx)
		free(e->mlx);
	if (e->win)
		free(e->win);
	free(e);
}

t_env			*ft_envnew(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, NAME);
	init_screen(&e->screen, e->mlx, WIDTH, HEIGHT);
	e->offset_x = 0.f;
	e->offset_y = 0.f;
	e->zoom = 1.f;
	e->click_pos_x = 0;
	e->click_pos_y= 0;
	e->move_pos_x = 0;
	e->move_pos_y = 0;
	e->pal = init_image(e->mlx, T_COLORS, 256, 1);
	return (e);
}
