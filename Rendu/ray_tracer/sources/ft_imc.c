/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset </var/mail/glasset>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 12:37:07 by glasset           #+#    #+#             */
/*   Updated: 2014/03/19 17:22:25 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>


int				comment_m(t_env *e, char *str, int c, int flag)
{
	(void)e;
	(void)str;
	(void)c;
	(void)flag;
	return (0);
}

int				m_open(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (check_arg(tmp[1], 0) == -1)
			return (-2);
	if (flag == T_HYPERBOLE)
		e->meshes[c].prim.hyperbole.open = ft_atod(tmp[1]);
	else
		return (-1);
	return (2);
}

int				m_normal(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	tmp = ft_strsplit(str, BREAK);
	tmp = ft_strsplit(tmp[1], BREAK2);
	if (check_arg(tmp[0], 0) == -1)
			return (-2);
	if (check_arg(tmp[1], 0) == -1)
			return (-2);
	if (check_arg(tmp[2], 0) == -1)
			return (-2);
	if (flag == T_PLAN)
	{
		e->meshes[c].prim.plan.normal = init_vec(ft_atod(tmp[0]), ft_atod(tmp[1]),
				ft_atod(tmp[2]));
		return (2);
	}
	return (-1);
}

int				m_rotate(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	tmp = ft_strsplit(tmp[1], BREAK2);
	if (check_arg(tmp[0], 0) == -1)
			return (-2);
	if (check_arg(tmp[1], 0) == -1)
			return (-2);
	if (check_arg(tmp[2], 0) == -1)
			return (-2);
	inv_rot_matrix_x(&e->meshes[c].rot_x, ft_atod(tmp[0]));
	inv_rot_matrix_y(&e->meshes[c].rot_y, ft_atod(tmp[1]));
	inv_rot_matrix_z(&e->meshes[c].rot_z, ft_atod(tmp[2]));
	return (0);
}

int				m_coef(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (check_arg(tmp[1], 1) == -1)
			return (-2);
	if (flag == T_CONE)
		e->meshes[c].prim.cone.coeff = ft_atod(tmp[1]);
	else if (flag == T_PARABOLE)
		e->meshes[c].prim.parabole.coeff = ft_atod(tmp[1]);
	else if (flag == T_HYPERBOLE)
		e->meshes[c].prim.hyperbole.coeff = ft_atod(tmp[1]);
	else
		return (-1);
	return (2);
}

int				init_flag(t_env *e, int type, int c)
{
	e->meshes[c].type = type;
	return (type);
}

int				color_m(t_env *e, char *str, int c, int flag)
{
	char		**tmp;
	int			i;

	i = 0;
	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	tmp[1] = ft_strsub(tmp[1], cut_space(tmp[1]), ft_strlen(tmp[1]));
	while (tmp[1][i])
		i++;
	if (i != 9)
	{
		tmp[1][0] = '0';
		tmp[1][1] = '\0';
		i = -1;
	}
	else
		i = 0;
	e->meshes[c].color = get_color(tmp[1]);
	return (i);
}

int				m_diffuse(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	if (check_arg(tmp[1], 1) == -1)
			return (-2);
	e->meshes[c].diff = ft_atod(tmp[1]);
	return (0);
}

int				m_radius(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (check_arg(tmp[1], 0) == -1)
			return (-2);
	if (flag == T_SPHERE)
		e->meshes[c].prim.sphere.radius = ft_atod(tmp[1]);
	else if (flag == T_CYLINDER)
		e->meshes[c].prim.cylinder.radius = ft_atod(tmp[1]);
	else
		return (-1);
	return (2);
}

int				m_specular(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	tmp = ft_strsplit(tmp[1], BREAK2);
	if (check_arg(tmp[0], 1) == -1)
			return (-2);
	e->meshes[c].spec = ft_atod(tmp[0]);
	return (0);
}

int				m_reflection(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	if (check_arg(tmp[1], 1) == -1)
			return (-2);
	e->meshes[c].refl = ft_atod(tmp[1]);
	return (0);
}

int				m_refraction(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	if (check_arg(tmp[1], 1) == -1)
			return (-2);
	e->meshes[c].refr = ft_atod(tmp[1]);
	return (0);
}

int				m_scale(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	tmp = ft_strsplit(tmp[1], BREAK2);
	if (check_arg(tmp[0], 1) == -1)
		return (-2);
	if (check_arg(tmp[1], 1) == -1)
		return (-2);
	if (check_arg(tmp[2], 1) == -1)
		return (-2);
	inv_scale_matrix(&e->meshes[c].scale, ft_atod(tmp[0]), ft_atod(tmp[1]), ft_atod(tmp[2]));
	return (0);
}

int				m_position(t_env *e, char *str, int c, int flag)
{
	static char	**tmp;
	static int	i = 0;

	(void)flag;
	if (i == 0)
	{
		tmp = ft_strsplit(str, BREAK);
		tmp = ft_strsplit(tmp[1], BREAK2);
		if (check_arg(tmp[0], 0) == -1)
			return (-2);
		if (check_arg(tmp[1], 0) == -1)
			return (-2);
		if (check_arg(tmp[2], 0) == -1)
			return (-2);
		e->meshes[c].trans = malloc_matrix(4, 4);
		i = 1;
	}
	else
	{
		inv_trans_matrix(&e->meshes[c].trans, ft_atod(tmp[0]), ft_atod(tmp[1]),
				ft_atod(tmp[2]));
		compute_matrix(&e->meshes[c]);
		i = 0;
	}
	return (2);
}
