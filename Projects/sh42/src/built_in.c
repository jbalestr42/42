/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 02:07:49 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/26 12:57:03 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <libft.h>
#include <sh.h>

t_cmds					g_cmds[8] = {
	{"setenv", ft_setenv},
	{"unsetenv", ft_unsetenv},
	{"cd", ft_cd},
	{"env", ft_env},
	{"echo", ft_echo},
	{"exit", ft_exit},
	{"history", ft_history},
	{NULL, NULL}
};

static void				exec_fork_bt(pid_t father, t_bloc *bloc, t_list *envi)
{
	int					i;

	if (father > 0)
	{
		if (bloc->was_redir != -1)
			close(bloc->fd);
		waitpid(father, &bloc->success, WUNTRACED);
		if (bloc->success == 256)
			bloc->success = -1;
		if (ft_strequ(bloc->tcmd[0], "exit") == 1)
			exit(0);
	}
	if (father == 0)
	{
		if (bloc->was_redir != -1)
			ft_get_dup(bloc);
		i = 0;
		while (g_cmds[i].str)
		{
			if (ft_strequ(bloc->tcmd[0], g_cmds[i].str) == 1)
				bloc->success = g_cmds[i].func(bloc->tcmd, envi);
			i++;
		}
		exit (0);
	}
}

void					ft_built_in(t_bloc *bloc, t_list *envi)
{
	int					i;
	pid_t				father;

	if (bloc->was_redir == -1)
	{
		i = 0;
		while (g_cmds[i].str)
		{
			if (ft_strequ(bloc->tcmd[0], g_cmds[i].str) == 1)
				bloc->success = g_cmds[i].func(bloc->tcmd, envi);
			i++;
		}
	}
	else
	{
		father = fork();
		exec_fork_bt(father, bloc, envi);
	}
}

int						ft_check_built_in(char **c)
{
	int					i;

	i = 0;
	while (g_cmds[i].str)
	{
		if (ft_strequ(c[0], g_cmds[i].str) == 1)
			return (1);
		i++;
	}
	return (0);
}
