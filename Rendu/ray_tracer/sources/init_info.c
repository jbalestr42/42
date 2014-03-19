/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:41:58 by glasset           #+#    #+#             */
/*   Updated: 2014/03/19 17:26:48 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parser.h"
#include <stdio.h>

i			*ft_inf(void)
{
	i		*ft;

	ft = malloc(sizeof(ft) * 6);
	ft[0] = &comment_b;
	ft[1] = &nb_light;
	ft[2] = &nb_mesh;
	ft[3] = &pov;
	ft[4] = &look;
	ft[5] = &ambient;
	return (ft);
}

int			ambient(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL || check_arg(tmp[1], 1) == -1)
		return (-1);
	e->ambient = ft_atod(tmp[1]);
	return (0);
}

int			look(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL)
		return (-1);
	tmp = ft_strsplit(tmp[1], BREAK2);
	if (check_arg(tmp[0], 0) == -1)
		return (-1);
	if (check_arg(tmp[1], 0) == -1)
		return (-1);
	if (check_arg(tmp[2], 0) == -1)
		return (-1);
	e->look_at_point = init_vec(ft_atod(tmp[0]), ft_atod(tmp[1]),
			ft_atod(tmp[2]));
	return (0);
}

int			pov(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL)
		return (-1);
	tmp = ft_strsplit(tmp[1], BREAK2);
	if (check_arg(tmp[0], 0) == -1)
		return (-1);
	if (check_arg(tmp[1], 0) == -1)
		return (-1);
	if (check_arg(tmp[2], 0) == -1)
		return (-1);
	e->cam.pos = init_vec(ft_atod(tmp[0]), ft_atod(tmp[1]),
			ft_atod(tmp[2]));

	return (0);
}

int			checkline_inf(char *str)
{
	char	**tmp;
	if (str[0] == START_OBJ || str[0] == COMMENT)
		return (0);
	tmp = ft_strsplit(str, BREAK);
	tmp[0] = ft_strsub(tmp[0], cut_space(tmp[0]), ft_strlen(tmp[0]));
	if (!ft_strcmp(tmp[0], "numbers of light"))
		return (1);
	if (!ft_strcmp(tmp[0], "numbers of object"))
		return (2);
	if (!ft_strcmp(tmp[0], "point of view"))
		return (3);
	if (!ft_strcmp(tmp[0], "look at"))
		return (4);
	if (!ft_strcmp(tmp[0], "color ambient"))
		return (5);
	return (-1);
}

int			nb_mesh(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL || check_arg(tmp[1], 0) == -1)
		return (-1);
	e->nb_mesh_malloc = ft_atoi(tmp[1]);
	e->meshes = (t_mesh *)malloc(sizeof(t_mesh) * e->nb_mesh_malloc);
	return (0);
}

int			nb_light(t_env *e, char *str)
{
	char	**tmp;

	tmp = ft_strsplit(str, BREAK);
	if (tmp[1] == NULL || check_arg(tmp[1], 0) == -1)
		return (-1);
	e->nb_light_malloc = ft_atoi(tmp[1]);
	e->lights = (t_light *)malloc(sizeof(t_light) * e->nb_light_malloc);
	return (0);
}

int			information(t_env *e, int c_l, int fd, char *str)
{
	char	*line;
	int		l;
	i		*ft;
	int		tmp;
	int		count;

	count = 0;
	l = 1;
	ft = ft_inf();
	while (get_next_line(fd, &line))
	{
		if (line[0] == END_OBJ)
		{
			if (count == 5)
			{
				error_p(str, "\033[32m[OK]\033[0m info initialized", c_l);
				return (l);
			}
			error_p(str, "\033[31m[ERROR]\033[0m Some variable uninitialized in:", c_l);
			exit (0);
		}
		if (checkline_inf(line) == -1)
				error_p(ft_strsub(line, cut_space(line), ft_strlen(line)), "\033[31m[WARNING]\033[0m unknown line", l + c_l);
		else
			tmp = ft[checkline_inf(line)](e, line);
		if (tmp == -1)
		{
				error_p(ft_strsub(line, cut_space(line), ft_strlen(line)), "\033[31m[ERROR]\033[0m check value", l + c_l);
				exit (0);
		}
		else if (tmp == 0)
			count++;
		free(line);
		l++;
	}
	return (l);
}
