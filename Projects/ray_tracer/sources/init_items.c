/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:12:32 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 20:12:33 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "ray_tracer.h"

void				init_img(void *mlx, t_img *i, int width, int height)
{
	i->width = width;
	i->height = height;
	i->ptr = mlx_new_image(mlx, width, height);
	i->img = mlx_get_data_addr(i->ptr, &i->bpp, &i->size_line, &i->endian);
	i->bpp /= 8;
	i->max_size = i->size_line * height + i->bpp * width;
}

t_img				init_img_xpm(void *mlx, char *path, int width, int height)
{
	t_img			img;

	img.width = width;
	img.height = height;
	img.ptr = mlx_xpm_file_to_image(mlx, path, &width, &height);
	img.img = mlx_get_data_addr(img.ptr, &img.bpp, &img.size_line, &img.endian);
	img.bpp /= 8;
	img.max_size = img.size_line * height + img.bpp * width;
	return (img);
}

t_button			init_button(int x, int y, t_mouse_event *event, t_img img)
{
	t_button		button;

	button.x_pos = x;
	button.y_pos = y;
	button.state = NONE;
	button.img = img;
	button.frame_size = img.height / 2;
	button.event = event;
	button.check_box = 0;
	button.name = NULL;
	return (button);
}
