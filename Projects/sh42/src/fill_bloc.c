/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_bloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 18:49:20 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/20 18:52:09 by pvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sh.h>

static int				ft_get_bloc_cmd_size(char *bloc)
{
	int					i;
	int					size;

	i = 0;
	size = 0;
	while (bloc[i])
	{
		if (bloc[i] != '|' && bloc[i] != '&' && bloc[i] != ';')
			size++;
		i++;
	}
	return (size);
}

static int				fill_bloc_loop
	(int cmd_size, int j, char *new_bloc, t_elem *elem)
{
	int		i;

	i = 0;
	while (i < cmd_size)
	{
		elem->bloc->cmd[i] = new_bloc[j];
		i++;
		j++;
	}
	return (j);
}

int						ft_fill_bloc(t_list *cmds, char *new_bloc)
{
	t_elem				*elem;
	int					cmd_size;
	int					j;

	if (!(elem = ft_list_create_elem(TYPE_CMD)))
		return (0);
	j = 0;
	elem->bloc->success = -1;
	elem->bloc->sep_prev = ft_check_sep(new_bloc, j);
	cmd_size = ft_get_bloc_cmd_size(new_bloc);
	if (!(elem->bloc->cmd = (char *)malloc(sizeof(char) * cmd_size + 1)))
	{
		perror("ft_fill_bloc()");
		return (0);
	}
	j = g_sep_size[elem->bloc->sep_prev];
	j = fill_bloc_loop(cmd_size, j, new_bloc, elem);
	elem->bloc->cmd[cmd_size] = '\0';
	elem->bloc->sep_next = ft_check_sep(new_bloc, j);
	if (!(cmds = ft_list_push_back(cmds, elem)))
		return (0);
	return (1);
}
