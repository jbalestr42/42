/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 15:41:37 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/23 20:09:24 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sh.h>
#include <libft.h>

int					ft_execute_cmd(t_bloc *bloc, t_data *data)
{
	if ((bloc->redir = ft_get_redir(bloc->cmd)) == -1)
	{
		if (bloc->cmd_type == BLTI)
		{
			if (!(bloc->tcmd = ft_str_to_tab(bloc->cmd)))
				return (0);
			ft_built_in(bloc, data->envi);
		}
		else if (bloc->cmd_type == EXEC)
		{
			if (!(bloc->tcmd = ft_str_to_tab(bloc->cmd)))
				return (0);
			ft_pre_exec(bloc, data->envi);
		}
		else if (bloc->cmd_type == 0)
			ft_print_error(bloc->cmd);
	}
	else
	{
		if (ft_parse_redir_type(bloc, data))
			if ((bloc->cmd_type = ft_find_cmd(bloc->cmd, data->envi)))
				ft_exec_redir(bloc, data);
	}
	return (1);
}

static int			ft_check_pipe_cmd(t_elem *elem)
{
	if (elem->bloc->sep_next == PIPE
				&& (((elem->bloc->sep_prev == OR
					&& elem->prev->bloc->success == -1)
					|| (elem->bloc->sep_prev == AND
					&& elem->prev->bloc->success != -1))
					|| (elem->bloc->sep_prev == SEMICOLON
					|| elem->bloc->sep_prev == -1)))
		return (1);
	return (0);
}

static int			ft_do_pipe_cmd(t_data *data, t_elem *elem)
{
	pid_t			pid;
	int				str;

	pid = fork();
	if (pid > 0)
		waitpid(pid, &str, 0);
	if (pid == 0)
	{
		if (!ft_pipe(elem, data))
			return (0);
	}
	while (elem->bloc->sep_next == PIPE)
		elem = elem->next;
	elem->bloc->success = WEXITSTATUS(str);
	return (1);
}

int					ft_execute_cmds(t_data *data)
{
	t_elem			*elem;

	elem = data->cmds->begin;
	while (elem)
	{
		if (ft_check_pipe_cmd(elem))
		{
			if (!ft_do_pipe_cmd(data, elem))
				return (0);
		}
		else if ((elem->bloc->sep_prev == SEMICOLON
					|| elem->bloc->sep_prev == -1)
				|| (elem->bloc->sep_prev == OR && elem->prev
					&& elem->prev->bloc->success == -1)
				|| (elem->bloc->sep_prev == AND && elem->prev
					&& elem->prev->bloc->success != -1))
		{
			if (!ft_execute_cmd(elem->bloc, data))
				return (0);
		}
		elem = elem->next;
	}
	return (1);
}
