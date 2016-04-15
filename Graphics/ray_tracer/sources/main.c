/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:10:12 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 05:15:10 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "ray_tracer.h"

int			main(void)
{
	t_env	*e;

	e = NULL;
	if (!(e = init_env()))
		return (1);
	mlx_hook(e->win, 2, (1L << 0), key_hook_press, e);
	mlx_hook(e->win, 3, (1L << 1), key_hook_release, e);
	mlx_hook(e->win, 4, (1L << 2), mouse_hook_press, e);
	mlx_hook(e->win, 6, (1L << 6), mouse_hook_move, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
