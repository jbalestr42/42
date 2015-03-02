/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 20:15:21 by rdavid            #+#    #+#             */
/*   Updated: 2014/06/23 20:15:21 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sh.h>

int						ft_pre_exec(t_bloc *bloc, t_list *envi)
{
	pid_t				pid;

	if (bloc->tcmd[0] != NULL)
	{
		if ((pid = fork()) == -1)
			perror("42sh");
		if (pid > 0)
		{
			if (bloc->was_redir != -1)
				close(bloc->fd);
			if (waitpid(pid, &bloc->success, WUNTRACED) == -1)
				perror("42sh");
			if (bloc->success == 256)
				bloc->success = -1;
		}
		if (pid == 0)
		{
			if (bloc->was_redir != -1)
				ft_get_dup(bloc);
			ft_exec(bloc, envi);
		}
	}
	return (1);
}
