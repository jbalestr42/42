/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:13:09 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 18:37:24 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

double			ft_degre_to_radian(double degree)
{
	while (degree > 360)
		degree -= 360;
	while (degree < -360)
		degree += 360;
	return (degree * PI / 180);
}

double			ft_sin(double angle)
{
	return (sin(ft_degre_to_radian(angle)));
}

double			ft_cos(double angle)
{
	return (cos(ft_degre_to_radian(angle)));
}

double			ft_tan(double angle)
{
	return (tan(ft_degre_to_radian(angle)));
}

double			ft_square(double nb)
{
	return (nb * nb);
}
