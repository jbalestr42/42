/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset </var/mail/glasset>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:56:07 by glasset           #+#    #+#             */
/*   Updated: 2014/03/19 18:01:04 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"

m				*ft_inm(void)
{
	m			*ft;

	ft = malloc(sizeof(ft) * 13);
	ft[0] = &comment_m;
	ft[1] = &color_m;
	ft[2] = &m_diffuse;
	ft[3] = &m_specular;
	ft[4] = &m_reflection;
	ft[5] = &m_refraction;
	ft[6] = &m_normal;
	ft[7] = &m_rotate;
	ft[8] = &m_radius;
	ft[9] = &m_coef;
	ft[10] = &m_position;
	ft[11] = &m_scale;
	ft[12] = &m_open;
	return (ft);
}

int				checkline_mesh(char *str)
{
	char	**tmp;

	if (str[0] == START_OBJ || str[0] == COMMENT)
		return (0);
	tmp = ft_strsplit(str, BREAK);
	tmp[0] = ft_strsub(tmp[0], cut_space(tmp[0]), ft_strlen(tmp[0]));
	if (!ft_strcmp(tmp[0], "color"))
		return (1);
	if (!ft_strcmp(tmp[0], "diffuse"))
		return (2);
	if (!ft_strcmp(tmp[0], "specular"))
		return (3);
	if (!ft_strcmp(tmp[0], "reflection"))
		return (4);
	if (!ft_strcmp(tmp[0], "refraction"))
		return (5);
	if (!ft_strcmp(tmp[0], "normal"))
		return (6);
	if (!ft_strcmp(tmp[0], "rotation"))
		return (7);
	if (!ft_strcmp(tmp[0], "radius"))
		return (8);
	if (!ft_strcmp(tmp[0], "coef"))
		return (9);
	if (!ft_strcmp(tmp[0], "position"))
		return (10);
	if (!ft_strcmp(tmp[0], "scale"))
		return (11);
	if (!ft_strcmp(tmp[0], "open"))
		return (12);
	return (-1);
}

int				min_arg(int flag)
{
	if (flag == T_HYPERBOLE)
		return (3);
	return (2);
}

void			init_base(t_env *e, int flag, int c)
{
	(void)flag;
	/*f (flag == T_HYPERBOLE)
		e->meshes[c].prim.hyperbole.open = 0.0;
	if (flag == T_PLAN)
		e->meshes[c].prim.plan.normal = init_vec(0.0, 0.0, 0.0);*/
	e->meshes[c].rot_x = malloc_matrix(4, 4);
	e->meshes[c].rot_y = malloc_matrix(4, 4);
	e->meshes[c].rot_z = malloc_matrix(4, 4);
	inv_rot_matrix_x(&e->meshes[c].rot_x, 0.0);
	inv_rot_matrix_y(&e->meshes[c].rot_y, 0.0);
	inv_rot_matrix_z(&e->meshes[c].rot_z, 0.0);
	/*if (flag == T_CONE)
		e->meshes[c].prim.cone.coeff = 0.0;
	else if (flag == T_PARABOLE)
		e->meshes[c].prim.parabole.coeff = 0.0;
	else if (flag == T_HYPERBOLE)
		e->meshes[c].prim.hyperbole.coeff = 0.0;*/
	e->meshes[c].color.r = 1.0;
	e->meshes[c].color.g = 1.0;
	e->meshes[c].color.b = 1.0;
	e->meshes[c].diff = 0.8;
	/*if (flag == T_SPHERE)
		e->meshes[c].prim.sphere.radius = 0.0;
	else if (flag == T_CYLINDER)
		e->meshes[c].prim.cylinder.radius = 0.0;*/
	e->meshes[c].spec = 0.8;
	e->meshes[c].refl = 0.0;
	e->meshes[c].refr = 0.0;
	e->meshes[c].scale = malloc_matrix(4, 4);
	inv_scale_matrix(&e->meshes[c].scale, 0.2, 0.2, 0.2);
}

int				init_mesh(t_env *e, int c_l, int fd, char *str)
{
	static int	c = 0;
	int			l;
	int			flag;
	char		*line;
	m			*ft;
	int			tmp;
	int			count;

	count = 0;
	ft = ft_inm();
	l = 1;
	if (c == e->nb_mesh_malloc || e->nb_mesh_malloc == -1)
	{
		error_p(str, "Object ignored check number of object", c_l);
		while (get_next_line(fd, &line))
		{
			if (line[0] == END_OBJ)
				break ;
			l++;
		}
		return (l);
	}
	if (!ft_strcmp(str, "Sphere"))
		flag = init_flag(e, T_SPHERE, c);
	if (!ft_strcmp(str, "Plan"))
		flag = init_flag(e, T_PLAN, c);
	if (!ft_strcmp(str, "Cylinder"))
		flag = init_flag(e, T_CYLINDER, c);
	if (!ft_strcmp(str, "Cone"))
		flag = init_flag(e, T_CONE, c);
	if (!ft_strcmp(str, "Parabole"))
		flag = init_flag(e, T_PARABOLE, c);
	if (!ft_strcmp(str, "Hyperbole"))
		flag = init_flag(e, T_HYPERBOLE, c);
	init_base(e, flag, c);
	while (get_next_line(fd, &line))
	{
		tmp = 0;
		if (line[0] == END_OBJ)
		{
			if (count == min_arg(flag))
			{
				m_position(e, "", c,flag);
				error_p(str, "\033[32m[OK]\033[0m Object add", c_l);
				e->nb_mesh++;
				c++;
			}
			else
				error_p(str, "\033[31m[ERROR]\033[0m Some variable uninitialized in", c_l);
			return (l);
		}
		if (checkline_mesh(line) == -1)
			error_p(ft_strsub(line, cut_space(line), ft_strlen(line)), "\033[31m[WARNING]\033[0m unknown line", l + c_l);
		else
			tmp = ft[checkline_mesh(line)](e, line, c, flag);
		if (tmp == -1)
			error_p(ft_strsub(line, cut_space(line), ft_strlen(line)), "\033[31m[WARNING]\033[0m wrong value", c_l + l);
		if (tmp == -2)
		{
			error_p(ft_strsub(line, cut_space(line), ft_strlen(line)), "\033[31m[ERROR]\033[0m object ignored", c_l + l);
			free(line);
			return (l);
		}
		else if (tmp == 2)
			count++;
		l++;
	}
	return (l);
}
