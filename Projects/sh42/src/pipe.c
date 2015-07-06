/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 21:32:56 by rdavid            #+#    #+#             */
/*   Updated: 2014/06/23 21:32:56 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sh.h>

static int			ft_pipe_blti_exec(t_bloc *bloc, t_data *data)
{
	if (bloc->cmd_type == BLTI)
	{
		if (!(bloc->tcmd = ft_str_to_tab(bloc->cmd)))
			return (0);
		ft_built_in(bloc, data->envi);
		exit(0);
	}
	else if (bloc->cmd_type == EXEC)
	{
		if (!(bloc->tcmd = ft_str_to_tab(bloc->cmd)))
			return (0);
		ft_exec(bloc, data->envi);
	}
	else if (bloc->cmd_type == 0)
	{
		ft_print_error(bloc->cmd);
		exit(0);
	}
	return (1);
}

static int			ft_execute_pipe(t_elem *elem, t_data *data)
{
	t_bloc			*bloc;

	bloc = elem->bloc;
	if ((bloc->redir = ft_get_redir(bloc->cmd)) == -1)
	{
		if (!ft_pipe_blti_exec(elem->bloc, data))
			return (0);
	}
	else
	{
		if (ft_parse_redir_type(bloc, data))
		{
			if ((bloc->cmd_type = ft_find_cmd(bloc->cmd, data->envi)))
				ft_exec_redir(bloc, data);
		}
	}
	return (1);
}

static void			ft_pipe_father(int *pfd, t_elem *elem, t_data *data)
{
	wait(0);
	dup2(pfd[0], 0);
	close(pfd[0]);
	close(pfd[1]);
	ft_pipe(elem->next, data);
}

static void			ft_pipe_son(int *pfd, t_elem *elem, t_data *data)
{
	wait(0);
	dup2(pfd[1], 1);
	close(pfd[0]);
	close(pfd[1]);
	ft_execute_pipe(elem, data);
}

int					ft_pipe(t_elem *elem, t_data *data)
{
	int				pfd[2];

	if (elem->bloc->sep_next != PIPE)
	{
		wait(0);
		ft_execute_pipe(elem, data);
	}
	if (pipe(pfd) == -1)
	{
		perror("42sh: ft_execute_pipe():");
		return (-1);
	}
	if (fork())
		ft_pipe_father(pfd, elem, data);
	else
		ft_pipe_son(pfd, elem, data);
	return (1);
}
