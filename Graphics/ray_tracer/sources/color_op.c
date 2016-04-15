/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:09:30 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 05:09:33 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

t_color			add_col_col(t_color col1, t_color col2)
{
	col1.r = col1.r + col2.r;
	col1.g = col1.g + col2.g;
	col1.b = col1.b + col2.b;
	return (col1);
}

t_color			prod_col_col(t_color col1, t_color col2)
{
	col1.r = col1.r * col2.r;
	col1.g = col1.g * col2.g;
	col1.b = col1.b * col2.b;
	return (col1);
}

t_color			add_col_val(t_color col, double value)
{
	col.r += value;
	col.g += value;
	col.b += value;
	return (col);
}

t_color			prod_col_val(t_color col, double value)
{
	col.r *= value;
	col.g *= value;
	col.b *= value;
	return (col);
}

t_color			init_color(double r, double g, double b)
{
	t_color		tmp;

	tmp.r = r;
	tmp.g = g;
	tmp.b = b;
	return (tmp);
}
