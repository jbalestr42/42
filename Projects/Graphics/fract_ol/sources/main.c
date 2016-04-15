/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:10:12 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/10 13:22:10 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

int		main(void)
{
	t_env	*e;

	if (!(e = ft_envnew()))
		return (1);
	mlx_hook(e->win, 2, (1L << 0), key_hook_press, e);
	mlx_hook(e->win, 4, (1L << 2), mouse_hook_press, e);
	mlx_hook(e->win, 6, (1L << 6), mouse_hook_move, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
