/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_screens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 06:56:10 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/07 16:46:00 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "ray_tracer.h"

static int			init_menu(t_env *e)
{
	e->screens[MENU].nb_button = 3;
	if (!(e->screens[MENU].buttons = (t_button *)malloc(sizeof(t_button) * 3)))
		return (0);
	e->screens[MENU].background = init_img_xpm(e->mlx,
					"images/background.xpm", 1440, 1080);
	e->screens[MENU].buttons[0] = init_button(WIDTH / 2 - 100, HEIGHT / 2,
					&mouse_event_ray_trace,
					init_img_xpm(e->mlx, "images/draw.xpm", 200, 200));
	e->screens[MENU].buttons[1] = init_button(WIDTH / 2 - 100, HEIGHT / 2 + 100,
					&mouse_event_options,
					init_img_xpm(e->mlx, "images/options.xpm", 200, 200));
	e->screens[MENU].buttons[2] = init_button(WIDTH / 2 - 100, HEIGHT / 2 + 200,
					&mouse_event_leave,
					init_img_xpm(e->mlx, "images/quit.xpm", 200, 200));
	return (1);
}

static int			init_options(t_env *e)
{
	e->screens[OPTIONS].nb_button = 1;
	e->screens[OPTIONS].buttons = (t_button *)malloc(sizeof(t_button) * 1);
	if (!e->screens[OPTIONS].buttons)
		return (0);
	e->screens[OPTIONS].buttons[0] = init_button(WIDTH / 2 - 100, HEIGHT / 2,
					&check_event_load_type,
					init_img_xpm(e->mlx, "images/check_render.xpm", 200, 200));
	e->screens[OPTIONS].buttons[0].check_box = 1;
	e->screens[OPTIONS].background = init_img_xpm(e->mlx,
					"images/background.xpm", 1440, 1080);
	return (1);
}

static int			init_ray_trace(t_env *e)
{
	init_img(e->mlx, &e->screens[RAY_TRACE].background, WIDTH, HEIGHT);
	return (1);
}

int					init_load_screen(t_env *e)
{
	e->screens[LOAD_SCREEN].nb_button = 1;
	e->screens[LOAD_SCREEN].buttons = (t_button *)malloc(sizeof(t_button) * 1);
	if (!e->screens[LOAD_SCREEN].buttons)
		return (0);
	e->screens[LOAD_SCREEN].buttons[0] = init_button(WIDTH / 2 - 100, HEIGHT / 2,
					&mouse_event_void,
					init_img_xpm(e->mlx, "images/draw.xpm", 200, 200));
	e->screens[LOAD_SCREEN].buttons[0].check_box = 1;
	e->screens[LOAD_SCREEN].background = init_img_xpm(e->mlx,
					"images/background.xpm", 1440, 1080);
	return (1);
}

int					init_screens(t_env *e)
{
	e->cur_screen = MENU;
	if (!(e->screens = (t_screen *)malloc(sizeof(t_screen) * 5)))
		return (0);
	if (!init_menu(e))
		return (0);
	if (!init_options(e))
		return (0);
	if (!init_choose_scene(e))
		return (0);
	if (!init_load_screen(e))
		return (0);
	if (!init_ray_trace(e))
		return (0);
	return (1);
}
