/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:18:05 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 17:58:41 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

int			ambient(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL || check_arg(tmp[1], 1) == -1)
		return (free_ret(-1, tmp));
	e->ambient = ft_atod(tmp[1]);
	return (free_ret(0, tmp));
}

int			nb_mesh(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL || check_arg(tmp[1], 0) == -1)
		return (free_ret(-1, tmp));
	e->nb_mesh_malloc = ft_atoi(tmp[1]);
	e->meshes = (t_mesh *)malloc(sizeof(t_mesh) * e->nb_mesh_malloc);
	return (free_ret(0, tmp));
}

int			nb_light(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL || check_arg(tmp[1], 0) == -1)
		return (free_ret(-1, tmp));
	e->nb_light_malloc = ft_atoi(tmp[1]);
	e->lights = (t_light *)malloc(sizeof(t_light) * e->nb_light_malloc);
	return (free_ret(0, tmp));
}

int			look(t_env *e, char *str)
{
	char	**tmp;
	char	**tmp1;

	tmp1 = ft_strsplit(str, BREAK);
	if (tmp1[1] == NULL)
		return (free_ret(-1, tmp1));
	tmp = ft_strsplit(tmp1[1], BREAK2);
	free_ret(0, tmp1);
	if (check_arg(tmp[0], 0) == -1)
		return (free_ret(-1, tmp));
	if (check_arg(tmp[1], 0) == -1)
		return (free_ret(-1, tmp));
	if (check_arg(tmp[2], 0) == -1)
		return (free_ret(-1, tmp));
	e->look_at_point = init_vec(ft_atod(tmp[0]), ft_atod(tmp[1]),
			ft_atod(tmp[2]));
	return (free_ret(0, tmp));
}

int			pov(t_env *e, char *str)
{
	char	**tmp;
	char	**tmp1;

	tmp1 = ft_strsplit(str, BREAK);
	if (tmp1[1] == NULL)
		return (free_ret(-1, tmp1));
	tmp = ft_strsplit(tmp1[1], BREAK2);
	free_ret(0, tmp1);
	if (check_arg(tmp[0], 0) == -1)
		return (free_ret(-1, tmp));
	if (check_arg(tmp[1], 0) == -1)
		return (free_ret(-1, tmp));
	if (check_arg(tmp[2], 0) == -1)
		return (free_ret(-1, tmp));
	e->cam.pos = init_vec(ft_atod(tmp[0]), ft_atod(tmp[1]),
			ft_atod(tmp[2]));
	return (free_ret(0, tmp));
}
