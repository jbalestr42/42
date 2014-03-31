/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meshe_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:12:14 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 19:13:42 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int				m_diffuse(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	if (check_arg(tmp[1], 1) == -1)
		return (free_ret(-2, tmp));
	e->meshes[c].diff = ft_atod(tmp[1]);
	return (free_ret(0, tmp));
}

int				m_radius(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (check_arg(tmp[1], 0) == -1)
		return (free_ret(-2, tmp));
	if (flag == T_SPHERE)
		e->meshes[c].prim.sphere.radius = ft_atod(tmp[1]);
	else if (flag == T_CYLINDER)
		e->meshes[c].prim.cylinder.radius = ft_atod(tmp[1]);
	else
		return (free_ret(-1, tmp));
	return (free_ret(2, tmp));
}

int				m_specular(t_env *e, char *str, int c, int flag)
{
	char		**tmp;
	char		**tmp1;

	(void)flag;
	tmp1 = ft_strsplit(str, BREAK);
	tmp = ft_strsplit(tmp1[1], BREAK2);
	free_ret(0, tmp1);
	if (check_arg(tmp[0], 1) == -1)
		return (free_ret(-2, tmp));
	e->meshes[c].spec = ft_atod(tmp[0]);
	return (free_ret(0, tmp));
}

int				m_reflection(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	if (check_arg(tmp[1], 1) == -1)
		return (free_ret(-2, tmp));
	e->meshes[c].refl = ft_atod(tmp[1]);
	return (free_ret(0, tmp));
}

int				m_refraction(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	(void)flag;
	tmp = ft_strsplit(str, BREAK);
	if (check_arg(tmp[1], 1) == -1)
		return (free_ret(-2, tmp));
	e->meshes[c].refr = ft_atod(tmp[1]);
	return (free_ret(0, tmp));
}
