/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 15:47:30 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/05 15:55:06 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

static int		ft_fabs(float f)
{
	if (f < 0.0)
		return (f);
	return (-f);
}

double			ft_sqrt(double x, double error)
{
	double	b;
	double	res;
	int		bit;

	if (x <= 0.0 || x > DBL_MAX)
		return ((x <= 0.0) ? 0.0 : DBL_MAX);
	if (x >= 2.0 && x <= (double)(1LL << 63))
	{
		bit = 63;
		while ((double)(1LL << bit) > x)
			bit -= 2;
		b = (double)(1 << (bit / 2));
	}
	else
		b = x;
	res = error;
	while (ft_fabs(res - b) > error)
	{
		res = (res + b) / 2;
		b = x / res;
	}
	return (res);
}
