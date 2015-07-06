/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mesh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/14 11:56:07 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 19:46:18 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"

t_m				*ft_inm(void)
{
	t_m			*ft;

	ft = malloc(sizeof(ft) * 16);
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
	ft[13] = &m_v;
	ft[14] = &m_mat;
	ft[15] = &m_perlin;
	return (ft);
}

static int		check_lm(char **tmp)
{
	if (!ft_strcmp(tmp[0], "radius"))
		return (free_ret(8, tmp));
	if (!ft_strcmp(tmp[0], "coef"))
		return (free_ret(9, tmp));
	if (!ft_strcmp(tmp[0], "position"))
		return (free_ret(10, tmp));
	if (!ft_strcmp(tmp[0], "scale"))
		return (free_ret(11, tmp));
	if (!ft_strcmp(tmp[0], "open"))
		return (free_ret(12, tmp));
	if (!ft_strcmp(tmp[0], "vertex"))
		return (free_ret(13, tmp));
	if (!ft_strcmp(tmp[0], "material"))
		return (free_ret(14, tmp));
	if (!ft_strcmp(tmp[0], "perlin"))
		return (free_ret(15, tmp));
	return (free_ret(-1, tmp));
}

int				checkline_mesh(char *str)
{
	char	**tmp;
	char	*line;

	if (str[0] == START_OBJ || str[0] == COMMENT)
		return (0);
	tmp = ft_strsplit(str, BREAK);
	line = tmp[0];
	tmp[0] = ft_strsub(tmp[0], cut_space(tmp[0]), ft_strlen(tmp[0]));
	free(line);
	if (!ft_strcmp(tmp[0], "color"))
		return (free_ret(1, tmp));
	if (!ft_strcmp(tmp[0], "diffuse"))
		return (free_ret(2, tmp));
	if (!ft_strcmp(tmp[0], "specular"))
		return (free_ret(3, tmp));
	if (!ft_strcmp(tmp[0], "reflection"))
		return (free_ret(4, tmp));
	if (!ft_strcmp(tmp[0], "refraction"))
		return (free_ret(5, tmp));
	if (!ft_strcmp(tmp[0], "normal"))
		return (free_ret(6, tmp));
	if (!ft_strcmp(tmp[0], "rotation"))
		return (free_ret(7, tmp));
	return (check_lm(tmp));
}

static int		init_all_m(t_env *e, char *str, int c)
{
	int			flag;

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
	if (!ft_strcmp(str, "Triangle"))
		flag = init_flag(e, T_TRIANGLE, c);
	init_base(e, flag, c);
	return (flag);
}

int				init_mesh(t_env *e, int c_l, int fd, char *str)
{
	t_imesh		j;

	j.count = 0;
	j.l = 1;
	e->i_pos = 0;
	if (e->nb_mesh == e->nb_mesh_malloc || e->nb_mesh_malloc == -1)
		return (check_mesh_nb(str, fd, c_l));
	j.flag = init_all_m(e, str, e->nb_mesh);
	while (get_next_line(fd, &j.line))
	{
		j.tmp = 0;
		j.cbis = e->nb_mesh;
		j.ret_m = check_end_mesh(e, &j, str, c_l);
		if (j.ret_m > -1)
			return (j.l);
		call_ft(e, &j, e->nb_mesh, c_l);
		if (check_tmp(j.line, c_l, j.l, j.tmp) == 0)
			return (j.l);
		else if (j.tmp == 2)
			j.count++;
		j.l++;
		free(j.line);
	}
	return (j.l);
}
