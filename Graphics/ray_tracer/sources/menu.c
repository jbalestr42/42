/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 22:54:12 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 05:15:29 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include "menu.h"

int				check_scene_name(char *s)
{
	int				i;

	i = 0;
	while (s[i])
		i++;
	if (i < 4)
		return (0);
	if (s[--i] != 't')
		return (0);
	if (s[--i] != 'r')
		return (0);
	if (s[--i] != '.')
		return (0);
	return (1);
}

static int		is_valid_file(char *s)
{
	if (check_scene_name(s))
	{
		ft_putstr("Scene name : ");
		ft_putstr(s);
		write(1, "\n", 1);
		return (1);
	}
	ft_putstr("Invalid scene name : ");
	ft_putstr(s);
	write(1, "\n", 1);
	return (0);
}

int				count_scene(t_env *e)
{
	int				nb_button;
	DIR				*dp;
	struct dirent	*ep;

	nb_button = 0;
	if ((dp = opendir("scenes/")))
	{
		while ((ep = readdir(dp)))
		{
			if (ep->d_name[0] != '.')
				nb_button = nb_button + is_valid_file(ep->d_name);
		}
		closedir(dp);
	}
	else
		ft_error(1, e, "Couldn't open the directory.");
	return (nb_button);
}

int				count_panel(t_env *e)
{
	int		i;
	int		j;

	i = count_scene(e);
	j = 1 + ((i - 1) / 4);
	return (j);
}
