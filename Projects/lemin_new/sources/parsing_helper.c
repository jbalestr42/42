/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 20:07:59 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/15 17:12:53 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			return_print(int ret, char *message)
{
	ft_putstr(message);
	ft_putendl(".");
	return (ret);
}

int			return_free_tab(char *line, char **tab, int ret, char *message)
{
	if (!ret && message)
	{
		ft_putstr(message);
		ft_putendl(".");
	}
	if (line)
		free(line);
	if (tab)
		free_split(tab);
	return (ret);
}

int			return_free(char *line, int ret, char *message)
{
	if (!ret && message)
	{
		ft_putstr(message);
		ft_putendl(".");
	}
	if (line)
		free(line);
	return (ret);
}

int			is_number(char *line)
{
	int		i;

	i = 0;
	while (i < ft_strlen(line))
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}
