/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:13:09 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 22:31:51 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <mlx.h>
#include <stdlib.h>

static void		del_images(t_env *e)
{
	int		i;

	i = 0;
	while (i < NB_WALL)
	{
		if (e->walls[i].ptr)
			mlx_destroy_image(e->mlx, e->walls[i].ptr);
		i++;
	}
	if (e->screen.ptr)
		mlx_destroy_image(e->mlx, e->screen.ptr);
	if (e->sky.ptr)
		mlx_destroy_image(e->mlx, e->sky.ptr);
	if (e->splash.ptr)
		mlx_destroy_image(e->mlx, e->splash.ptr);
}

void			ft_envdel(t_env *e)
{
	int		i;

	i = 0;
	if (!e)
		return ;
	if (e->map)
	{
		while (i < e->map_height)
		{
			free(e->map[i]);
			i++;
		}
	}
	del_images(e);
	if (e->mlx)
		free(e->mlx);
	if (e->win)
		free(e->win);
	free(e);
}

t_env			*ft_envnew(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, NAME);
	init_map(e, "maps/map1");
	e->fov = 60;
	e->dist_plan_player = (WIDTH / 2) / ft_tan(e->fov / 2);
	e->step_angle = (float)e->fov / WIDTH;
	e->dist_size = SIZE * e->dist_plan_player;
	e->current_height = HEIGHT / 2;
	e->sky = init_image(e->mlx, T_SKY, 1580, 800);
	e->splash = init_image(e->mlx, T_SPLASH, 1580, 800);
	e->hud = init_image(e->mlx, T_HUD, 252, 268);
	init_sprite_hud(&e->hud, 4, 67);
	e->weapon = init_image(e->mlx, T_WEAPON, 450, 2200);
	init_sprite_hud(&e->weapon, 4, 550);
	e->screen = init_screen(e->mlx, WIDTH, HEIGHT);
	e->trig_event = NULL;
	init_walls(e);
	init_events(e);
	e->current_wall = &e->walls[0];
	return (e);
}
