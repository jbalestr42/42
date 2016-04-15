/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 12:08:48 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 17:18:04 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "ray_tracer.h"

void			del_parse(t_env *e)
{
	int			delc;

	delc = -1;
	while (++delc < e->nb_mesh)
	{
		free_matrix(e->meshes[delc].trans, 4);
		free_matrix(e->meshes[delc].scale, 4);
		free_matrix(e->meshes[delc].rot_x, 4);
		free_matrix(e->meshes[delc].rot_y, 4);
		free_matrix(e->meshes[delc].rot_z, 4);
		free_matrix(e->meshes[delc].result, 4);
	}
	if (e->meshes)
		free(e->meshes);
	e->meshes = NULL;
	if (e->lights)
		free(e->lights);
	e->lights = NULL;
}

static void		del_screens(t_env *e)
{
	int			i;
	int			j;

	i = -1;
	while (++i < 4 + e->nb_panel)
	{
		if (e->screens[i].buttons)
		{
			j = -1;
			while (++j < e->screens[i].nb_button)
			{
				if (e->screens[i].buttons[j].img.ptr)
					mlx_destroy_image(e->mlx, e->screens[i].buttons[j].img.ptr);
				if (e->screens[i].buttons[j].name)
					free(e->screens[i].buttons[j].name);
			}
			free(e->screens[i].buttons);
		}
		if (e->screens[i].background.ptr)
			mlx_destroy_image(e->mlx, e->screens[i].background.ptr);
	}
	free(e->screens);
}

static void		del_env(t_env *e)
{
	int			i;

	if (!e)
		return ;
	del_parse(e);
	if (e->img_tmp.ptr)
		mlx_destroy_image(e->mlx, e->img_tmp.ptr);
	i = -1;
	while (++i < 180)
	{
		if (e->vid[i].ptr)
			mlx_destroy_image(e->mlx, e->vid[i].ptr);
	}
	while (e->start != NULL)
	{
		close(e->start->fd);
		e->start = e->start->next;
	}
	if (e->screens)
		del_screens(e);
	free(e->mlx);
	free(e->win);
}

void			ft_error(int b_exit, t_env *e, char *str)
{
	del_env(e);
	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	if (b_exit)
	{
		write(2, "Exit.\n", 6);
		exit(1);
	}
}
