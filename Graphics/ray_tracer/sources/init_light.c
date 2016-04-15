/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glasset <glasset@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 14:16:46 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 19:48:43 by glasset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

static int	light_ign(int c_l, int fd, char *str)
{
	char	*line;
	int		li;

	li = 1;
	error_p(ft_strdup(str), "light ignored check number of light", c_l);
	while (get_next_line(fd, &line))
	{
		if (line[0] == END_OBJ)
		{
			free(line);
			break ;
		}
		free(line);
		li++;
	}
	return (li);
}

static int	print_mess(char *line, int c_l, int li, int tmp)
{
	if (tmp == -1)
		error_p(ft_strsub(line, cut_space(line), ft_strlen(line)),
				"\033[31m[WARNING]\033[0m wrong value", c_l + li);
	if (tmp == -2)
	{
		error_p(ft_strsub(line, cut_space(line), ft_strlen(line)),
				"\033[31m[ERROR]\033[0m light ignored", c_l + li);
		free(line);
		return (-1);
	}
	return (0);
}

static int	ret_light(char *str, int c_l, int li, t_env *e)
{
	if (e->i_pos != 2)
		error_p(ft_strdup(str),
				"\033[31m[ERROR]\033[0m Some variable uninitialized in",
				c_l);
	else
	{
		error_p(ft_strdup(str), "\033[32m[OK]\033[0m Light add", c_l);
		e->nb_light++;
	}
	return (li);
}

static char	*free_li(char *str, char *line, t_l *ft)
{
	free(ft);
	free(line);
	return (str);
}

int			light(t_env *e, int c_l, int fd, char *str)
{
	char		*line;
	t_l			*ft;
	int			li;
	int			tmp;

	li = 1;
	e->i_pos = 0;
	if (e->nb_light == e->nb_light_malloc || e->nb_light_malloc == -1)
		return (light_ign(c_l, fd, str));
	ft = ft_inl();
	while (get_next_line(fd, &line))
	{
		if (line[0] == END_OBJ)
			return (ret_light(free_li(str, line, ft), c_l, li, e));
		if (checkline_light(line) == -1)
			error_p(ft_strsub(line, cut_space(line), ft_strlen(line)),
				"\033[31m[WARNING]\033[0m unknown line", li + c_l);
		else
			tmp = ft[checkline_light(line)](e, line, e->nb_light);
		if (print_mess(line, c_l, li, tmp) == -1)
			return (free_l(li, (char *)ft));
		free(line);
		li++;
	}
	return (li);
}
