/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_meshe_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 13:54:09 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 18:44:48 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int				comment_m(t_env *e, char *str, int c, int flag)
{
	(void)e;
	(void)str;
	(void)c;
	(void)flag;
	return (0);
}

int				m_perlin(t_env *e, char *str, int c, int flag)
{
	char		**tmp;
	char		**tmp1;
	int			i;

	i = 0;
	tmp1 = ft_strsplit(str, BREAK);
	tmp = ft_strsplit(tmp1[1], BREAK2);
	free_ret(flag, tmp1);
	i = check_col(tmp[0]);
	i += check_col(tmp[1]);
	i += check_col(tmp[2]);
	if (i < 0)
	{
		e->meshes[c].mat.col1 = get_color(COLOR_PERL);
		e->meshes[c].mat.col2 = get_color(COLOR_PERL);
		e->meshes[c].mat.col3 = get_color(COLOR_PERL);
		return (free_ret(-1, tmp));
	}
	else
	{
		e->meshes[c].mat.col1 = get_color(tmp[0]);
		e->meshes[c].mat.col2 = get_color(tmp[1]);
		e->meshes[c].mat.col3 = get_color(tmp[2]);
	}
	return (free_ret(0, tmp));
}

int				m_mat(t_env *e, char *str, int c, int flag)
{
	char		**tmp;
	char		*line;

	tmp = ft_strsplit(str, BREAK);
	line = ft_strsub(tmp[1], cut_space(tmp[1]), ft_strlen(tmp[1]));
	if (!ft_strcmp(line, "wood;"))
		e->meshes[c].mat.type = WOOD;
	else if (!ft_strcmp(line, "marble;"))
		e->meshes[c].mat.type = MARBLE;
	else if (!ft_strcmp(line, "checker1;") && flag == T_PLAN)
		e->meshes[c].mat.type = CHECKER1;
	else if (!ft_strcmp(line, "checker2;") && flag == T_PLAN)
		e->meshes[c].mat.type = CHECKER2;
	else if (!ft_strcmp(line, "checker3;") && flag == T_PLAN)
		e->meshes[c].mat.type = CHECKER3;
	else if (!ft_strcmp(line, "zebra;"))
		e->meshes[c].mat.type = ZEBRA;
	else
	{
		free_l(0, line);
		return (free_ret(-1, tmp));
	}
	free_l(0, line);
	return (free_ret(0, tmp));
}

int				m_v(t_env *e, char *str, int c, int flag)
{
	char		**tmp;
	char		**tmp1;
	static int	i = 0;
	double		dot[3];

	tmp1 = ft_strsplit(str, BREAK);
	tmp = ft_strsplit(tmp1[1], BREAK2);
	free_ret(0, tmp1);
	if (check_arg(tmp[0], 0) == -1 || check_arg(tmp[1], 0) == -1
			|| check_arg(tmp[2], 0) == -1)
		return (free_ret(-2, tmp));
	dot[0] = ft_atod(tmp[0]);
	dot[1] = ft_atod(tmp[1]);
	dot[2] = ft_atod(tmp[2]);
	if (flag == T_TRIANGLE)
	{
		i = m_vertex(e, c, i, dot);
		return (free_ret(2, tmp));
	}
	return (free_ret(-1, tmp));
}

int				m_open(t_env *e, char *str, int c, int flag)
{
	char		**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (check_arg(tmp[1], 0) == -1)
		return (free_ret(-2, tmp));
	if (flag == T_HYPERBOLE)
		e->meshes[c].prim.hyperbole.open = ft_atod(tmp[1]);
	else
		return (free_ret(-1, tmp));
	return (free_ret(2, tmp));
}
