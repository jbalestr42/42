/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/25 19:32:17 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/25 19:07:19 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sh.h>
#include <libft.h>
#include <unistd.h>

int						ft_exec(t_bloc *bloc, t_list *envi)
{
	char				*cmd;

	if (ft_isalnum(bloc->tcmd[0][0]))
		cmd = ft_find_cmd_path(bloc->tcmd[0], envi);
		else
	if (!(cmd = ft_check_exist(bloc->tcmd[0])))
		return (0);
	if (!cmd)
	{
		ft_putstr_fd("42sh: command not found:", 2);
		ft_putendl(bloc->tcmd[0]);
		exit(0);
	}
	else
	{
		if ((bloc->success = execve(cmd, bloc->tcmd,
									ft_env_to_array(envi)) == -1))
		{
			ft_putstr_fd("42sh: ", 2);
			perror(bloc->tcmd[0]);
			exit(-1);
		}
	}
	return (1);
}
