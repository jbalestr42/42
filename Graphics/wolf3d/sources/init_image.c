/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:35:30 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 21:22:43 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <mlx.h>

t_img		init_screen(void *mlx, int width, int height)
{
	t_img	img;

	img.width = width;
	img.height = height;
	img.ptr = mlx_new_image(mlx, width, height);
	img.img = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	img.bpp /= 8;
	img.max_size = img.size_line * height + img.bpp * width;
	return (img);
}

t_img		init_image(void *mlx, char *path, int width, int height)
{
	t_img	img;

	img.width = width;
	img.height = height;
	img.ptr = mlx_xpm_file_to_image(mlx, path, &width, &height);
	img.img = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	img.bpp /= 8;
	img.max_size = img.size_line * height + img.bpp * width;
	img.frame_size = width;
	return (img);
}

void		init_sprite(t_img *img, int nb_frame, int type, int speed)
{
	img->frames = nb_frame;
	img->current_frame = 0;
	img->speed = speed;
	img->type = type;
}

void		init_portraits(t_env *e)
{
	e->walls[7] = init_image(e->mlx, T_REALVES, 256, 256);
	init_sprite(&e->walls[7], 1, REALVES, 0);
	e->walls[8] = init_image(e->mlx, T_MVALLET, 256, 256);
	init_sprite(&e->walls[8], 1, MVALLET, 0);
	e->walls[9] = init_image(e->mlx, T_GEXBRAYA, 256, 256);
	init_sprite(&e->walls[9], 1, GEXBRAYA, 0);
	e->walls[10] = init_image(e->mlx, T_JBALESTR, 256, 256);
	init_sprite(&e->walls[10], 1, JBALESTR, 0);
	e->walls[11] = init_image(e->mlx, T_TCHARLAT, 256, 256);
	init_sprite(&e->walls[11], 1, TCHARLAT, 0);
	e->walls[12] = init_image(e->mlx, T_PCIAVALD, 256, 256);
	init_sprite(&e->walls[12], 1, PCIAVALD, 0);
	e->walls[13] = init_image(e->mlx, T_FCORBEL, 256, 256);
	init_sprite(&e->walls[13], 1, FCORBEL, 0);
	e->walls[14] = init_image(e->mlx, T_EVILEVIL, 256, 256);
	init_sprite(&e->walls[14], 1, EVILEVIL, 0);
	e->walls[15] = init_image(e->mlx, T_GLASSET, 256, 256);
	init_sprite(&e->walls[15], 1, GLASSET, 0);
	e->walls[16] = init_image(e->mlx, T_MROUX, 256, 256);
	init_sprite(&e->walls[16], 1, MROUX, 0);
}

void		init_walls(t_env *e)
{
	e->walls[0] = init_image(e->mlx, T_WALL, 32, 32);
	init_sprite(&e->walls[0], 1, WALL, 0);
	e->walls[1] = init_image(e->mlx, T_DISCO, 16, 128);
	init_sprite(&e->walls[1], 8, DISCO, 1);
	e->walls[2] = init_image(e->mlx, T_DOOR, 32, 32);
	init_sprite(&e->walls[2], 1, DOOR, 0);
	e->walls[3] = init_image(e->mlx, T_CAT, 256, 13568);
	init_sprite(&e->walls[3], 53, CAT, 2);
	e->walls[4] = init_image(e->mlx, T_CATLEFT, 200, 7200);
	init_sprite(&e->walls[4], 36, CAT_LEFT, 2);
	e->walls[5] = init_image(e->mlx, T_CATRIGHT, 200, 7200);
	init_sprite(&e->walls[5], 36, CAT_RIGHT, 2);
	e->walls[6] = init_image(e->mlx, T_DOORCAT, 280, 5880);
	init_sprite(&e->walls[6], 21, DOOR_CAT, 2);
	init_portraits(e);
}
