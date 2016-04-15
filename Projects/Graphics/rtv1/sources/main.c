/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:10:12 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 13:52:08 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "ray_tracer.h"

int			main(int argc, char **argv)
{
	t_env	*e;

	e = NULL;
	if (argc != 2)
		ft_error(1, e, "You need only one argument.\n");
	if (!(e = init_env(argv[1])))
		return (1);
	draw_view(e);
	mlx_hook(e->win, 2, (1L << 0), key_hook_press, e);
	mlx_hook(e->win, 3, (1L << 1), key_hook_release, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
