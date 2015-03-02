/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/23 22:40:13 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/25 21:10:24 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <sh.h>
#include <libft.h>

static int			ft_copy_original_env(t_list *envi, char **environ)
{
	int				i;
	t_elem			*elem;

	i = 0;
	while (environ[i] != NULL)
	{
		if (!(elem = ft_list_create_elem(TYPE_DATA)))
			return (0);
		elem->data = ft_strdup(environ[i]);
		if (!ft_list_push_back(envi, elem))
			return (0);
		i++;
	}
	return (1);
}

static int			ft_update_shlvl(t_list *envi)
{
	char			*lvl;
	char			*line;

	lvl = ft_find_in_envi(envi, "SHLVL");
	lvl[0]++;
	if (!(line = ft_strjoin("SHLVL=", lvl)))
		return (0);
	if (!ft_replace_line(envi, "SHLVL", line))
		return (0);
	return (1);
}

int					ft_init_data(t_list *envi, char **environ)
{
	if (!ft_copy_original_env(envi, environ))
		return (0);
	if (!ft_update_shlvl(envi))
		return (0);
	return (1);
}
