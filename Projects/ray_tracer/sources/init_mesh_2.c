/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mesh_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 10:29:41 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 19:49:27 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

int			check_mesh_nb(char *str, int fd, int c_l)
{
	char	*line;
	int		l;

	l = 1;
	error_p(ft_strdup(str), "Object ignored check number of object", c_l);
	while (get_next_line(fd, &line))
	{
		if (line[0] == END_OBJ)
		{
			free(line);
			break ;
		}
		free(line);
		l++;
	}
	return (l);
}

int			check_tmp(char *line, int c_l, int l, int tmp)
{
	if (tmp == -1)
		error_p(ft_strsub(line, cut_space(line), ft_strlen(line)),
			"\033[31m[WARNING]\033[0m wrong value", c_l + l);
	if (tmp == -2)
	{
		error_p(ft_strsub(line, cut_space(line), ft_strlen(line)),
			"\033[31m[ERROR]\033[0m object ignored", c_l + l);
		free(line);
		return (0);
	}
	return (-1);
}

int			call_ft(t_env *e, t_imesh *j, int c, int c_l)
{
	t_m			*ft;

	ft = ft_inm();
	if (checkline_mesh(j->line) == -1)
		error_p(ft_strsub(j->line, cut_space(j->line), ft_strlen(j->line)),
			"\033[31m[WARNING]\033[0m unknown line", j->l + c_l);
	else
		j->tmp = ft[checkline_mesh(j->line)](e, j->line, c, j->flag);
	free(ft);
	return (j->tmp);
}

static void	init_triangle(t_env *e, int c)
{
	e->meshes[c].trans = malloc_matrix(4, 4);
	inv_trans_matrix(&e->meshes[c].trans, e->meshes[c].prim.triangle.v1.x,
		e->meshes[c].prim.triangle.v1.y, e->meshes[c].prim.triangle.v1.z);
	compute_matrix(&e->meshes[c]);
}

int			check_end_mesh(t_env *e, t_imesh *j, char *str, int c_l)
{
	if (j->line[0] == END_OBJ)
	{
		if (j->count == min_arg(j->flag))
		{
			if (j->flag == T_TRIANGLE)
				init_triangle(e, j->cbis);
			else
				m_position(e, "", j->cbis, j->flag);
			error_p(ft_strdup(str), "\033[32m[OK]\033[0m Object add", c_l);
			e->nb_mesh++;
			return (free_l(1, j->line));
		}
		else
			error_p(ft_strdup(str),
				"\033[31m[ERROR]\033[0m Some variable uninitialized in",
					c_l);
		return (free_l(0, j->line));
	}
	return (-1);
}
