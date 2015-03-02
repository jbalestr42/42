/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:35:30 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 11:58:04 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ray_tracer.h"

void	init_screen(void *mlx, t_img *i, int width, int height)
{
	i->width = width;
	i->height = height;
	i->ptr = mlx_new_image(mlx, width, height);
	i->img = mlx_get_data_addr(i->ptr, &i->bpp, &i->size_line, &i->endian);
	i->bpp /= 8;
	i->max_size = i->size_line * height + i->bpp * width;
}
