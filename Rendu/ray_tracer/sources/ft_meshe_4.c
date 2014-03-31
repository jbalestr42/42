/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meshe_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 09:45:03 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 18:44:45 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int				m_scale(t_env *e, char *str, int c, int flag)
{
	char		**tmp;
	char		**tmp1;

	(void)flag;
	tmp1 = ft_strsplit(str, BREAK);
	tmp = ft_strsplit(tmp1[1], BREAK2);
	free_ret(0, tmp1);
	if (check_arg(tmp[0], 1) == -1)
		return (free_ret(-2, tmp));
	if (check_arg(tmp[1], 1) == -1)
		return (free_ret(-2, tmp));
	if (check_arg(tmp[2], 1) == -1)
		return (free_ret(-2, tmp));
	inv_scale_matrix(&e->meshes[c].scale, ft_atod(tmp[0]), ft_atod(tmp[1]),
			ft_atod(tmp[2]));
	return (free_ret(0, tmp));
}

int				m_position(t_env *e, char *str, int c, int flag)
{
	static char	**tmp = NULL;
	char		**tmp1;

	if (e->i_pos == 0)
	{
		tmp1 = ft_strsplit(str, BREAK);
		tmp = ft_strsplit(tmp1[1], BREAK2);
		free_ret(0, tmp1);
		if (check_arg(tmp[0], 0) == -1)
			return (free_ret(-2, tmp));
		if (check_arg(tmp[1], 0) == -1)
			return (free_ret(-2, tmp));
		if (check_arg(tmp[2], 0) == -1)
			return (free_ret(-2, tmp));
		e->meshes[c].trans = malloc_matrix(4, 4);
		e->i_pos = 1;
	}
	else
	{
		inv_trans_matrix(&e->meshes[c].trans, ft_atod(tmp[0]), ft_atod(tmp[1]),
				ft_atod(tmp[2]));
		compute_matrix(&e->meshes[c]);
		free_ret(flag, tmp);
	}
	return (2);
}

int				min_arg(int flag)
{
	if (flag == T_HYPERBOLE)
		return (3);
	if (flag == T_TRIANGLE)
		return (3);
	return (2);
}

int				m_vertex(t_env *e, int c, int i, double *dot)
{
	if (i == 0)
		e->meshes[c].prim.triangle.v1 = init_vec(dot[0], dot[1], dot[2]);
	if (i == 1)
		e->meshes[c].prim.triangle.v2 = sub(init_vec(dot[0], dot[1], dot[2]),
				e->meshes[c].prim.triangle.v1);
	if (i == 2)
		e->meshes[c].prim.triangle.v3 = sub(init_vec(dot[0], dot[1], dot[2]),
				e->meshes[c].prim.triangle.v1);
	i++;
	if (i == 3)
	{
		e->meshes[c].prim.triangle.normal = cross(e->meshes[c].prim.triangle.v2,
				e->meshes[c].prim.triangle.v3);
		i = 0;
	}
	return (i);
}

void			init_base(t_env *e, int flag, int c)
{
	(void)flag;
	e->meshes[c].rot_x = malloc_matrix(4, 4);
	e->meshes[c].rot_y = malloc_matrix(4, 4);
	e->meshes[c].rot_z = malloc_matrix(4, 4);
	inv_rot_matrix_x(&e->meshes[c].rot_x, 0.0);
	inv_rot_matrix_y(&e->meshes[c].rot_y, 0.0);
	inv_rot_matrix_z(&e->meshes[c].rot_z, 0.0);
	e->meshes[c].mat.type = NO_MAT;
	e->meshes[c].color.r = 0.5;
	e->meshes[c].color.g = 0.5;
	e->meshes[c].color.b = 0.5;
	e->meshes[c].diff = 0.8;
	e->meshes[c].spec = 0.8;
	e->meshes[c].refl = 0.0;
	e->meshes[c].refr = 0.0;
	e->meshes[c].scale = malloc_matrix(4, 4);
	inv_scale_matrix(&e->meshes[c].scale, 0.2, 0.2, 0.2);
}
