/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_shading.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:08:53 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 05:08:55 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

t_color			cell_shading(t_env *e, t_color color)
{
	double		index;

	index = 0;
	if (e->cell_shading)
	{
		while (index <= 1)
		{
			if (color.r >= index && color.r < index + 0.15)
				color.r = index + (0.15 / 2);
			if (color.g >= index && color.g < index + 0.15)
				color.g = index + (0.15 / 2);
			if (color.b >= index && color.b < index + 0.15)
				color.b = index + (0.15 / 2);
			index += 0.15;
		}
	}
	return (color);
}
