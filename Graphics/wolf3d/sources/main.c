/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:10:12 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 18:20:55 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <mlx.h>

int		main(void)
{
	t_env	*e;

	if (!(e = ft_envnew()))
		return (1);
	mlx_hook(e->win, 2, (1L << 0), key_hook_press, e);
	mlx_hook(e->win, 3, (1L << 1), key_hook_release, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop_hook(e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
