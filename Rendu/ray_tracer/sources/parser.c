/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/13 15:30:30 by glasset           #+#    #+#             */
/*   Updated: 2014/03/19 17:26:48 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "parser.h"

int			comment(t_env *e, int c_l, int fd, char *str)
{
	e = e;
	str = str;
	c_l = c_l;
	fd = fd;
	return (0);
}

static int			check_line(char *str)
{
	if (!ft_strcmp(str, "information"))
		return (1);
	if (!ft_strcmp(str, "Sphere"))
		return (2);
	if (!ft_strcmp(str, "Plan"))
		return (2);
	if (!ft_strcmp(str, "Cylinder"))
		return (2);
	if (!ft_strcmp(str, "Cone"))
		return (2);
	if (!ft_strcmp(str, "Hyperbole"))
		return (2);
	if (!ft_strcmp(str, "Parabole"))
		return (2);
	if (!ft_strcmp(str, "light"))
		return (3);
	return (0);
}

int				comment_l(t_env *e, char *str, int c)
{
	e = e;
	c = c;
	str = str;
	return (0);
}
int				pos_l(t_env *e, char *str, int c)
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
	e->lights[c].pos = init_vec(ft_atod(tmp[0]), ft_atod(tmp[1]),
			ft_atod(tmp[2]));
	return (0);
}

int				color_l(t_env *e, char *str, int c)
{
	char		**tmp;
	int			i;


	i = 0;
	tmp = ft_strsplit(str, BREAK);
	tmp[1] = ft_strsub(tmp[1], cut_space(tmp[1]), ft_strlen(tmp[1]));
	while (tmp[1][i])
		i++;
	if (i != 9)
	{
		tmp[1][0] = 'f';
		tmp[1][1] = '\0';
		i = -1;
	}
	else
		i = 0;
	e->lights[c].color = get_color(tmp[1]);
	return (i);
}

l				*ft_inl(void)
{
	l			*ft;

	ft = malloc(sizeof(ft) * 3);
	ft[0] = &comment_l;
	ft[1] = &color_l;
	ft[2] = &pos_l;
	return (ft);
}

int				checkline_light(char *str)
{
	char		**tmp;

	if (str[0] == START_OBJ || str[0] == COMMENT)
		return (0);
	tmp = ft_strsplit(str, BREAK);
	tmp[0] = ft_strsub(tmp[0], cut_space(tmp[0]), ft_strlen(tmp[0]));
	if (!ft_strcmp(tmp[0], "color"))
		return (1);
	if (!ft_strcmp(tmp[0], "position"))
		return (2);
	return (-1);
}

int			light(t_env *e, int c_l, int fd, char *str)
{
	char		*line;
	static int	c = 0;
	int			li;
	l			*ft;
	int			tmp;

	ft = ft_inl();
	li = 1;
	if (c == e->nb_light_malloc || e->nb_light_malloc == -1)
	{
		error_p(str, "light ignored check number of light", c_l);
		while (get_next_line(fd, &line))
		{
			if (line[0] == END_OBJ)
				break ;
			li++;
		}
		return (li);
	}
	while (get_next_line(fd, &line))
	{
		if (line[0] == END_OBJ)
		{
			error_p(str, "\033[32m[OK]\033[0m Light add", c_l);
			e->nb_light++;
			c++;
			return (li);
		}
		if (checkline_light(line) == -1)
			error_p(ft_strsub(line, cut_space(line), ft_strlen(line)), "\033[31m[WARNING]\033[0m unknown line", li + c_l);
		else
			tmp = ft[checkline_light(line)](e, line, c);
		if (tmp == -1)
			error_p(ft_strsub(line, cut_space(line), ft_strlen(line)), "\033[31m[WARNING]\033[0m wrong value", c_l + li);
		if (tmp == -2)
		{
			error_p(ft_strsub(line, cut_space(line), ft_strlen(line)), "\033[31m[ERROR]\033[0m light ignored", c_l + li);
			free(line);
			return (li);
		}

		free(line);
		li++;
	}
	return (li);
}

void		parse(t_env *e, char *path)
{
	char	*line;
	int		fd;
	int		current_m;
	f		*ft;

	ft = funct();
	e->nb_mesh = 0;
	e->nb_light = 0;
	e->nb_mesh_malloc = -1;
	e->nb_light_malloc = -1;

	current_m = 1;
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		write(1, "\033[31m[ERROR]\033[0m Wrong file.\n", 28);
		exit(0);
	}
	while (get_next_line(fd, &line))
	{
		if (current_m == 4)
		{
			if (line[5] != '#')
			{
				write(1, "\033[31m[ERROR]\033[0m Wrong format file.\n", 35);
				exit(0);
			}
		}
		current_m += ft[check_line(line)](e, current_m, fd, line);
		current_m++;
		free(line);
	}
}
