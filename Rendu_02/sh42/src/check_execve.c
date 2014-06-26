/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_execve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 20:16:16 by rdavid            #+#    #+#             */
/*   Updated: 2014/06/25 22:36:51 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sh.h>

int						ft_check_execve(char **c, t_list *envi)
{
	char				*cmd;

	cmd = NULL;
	if (ft_isalnum(c[0][0]))
	{
		cmd = ft_find_cmd_path(c[0], envi);
		if (!cmd)
			return (0);
		free(cmd);
	}
	else
	{
		if (!(cmd = ft_check_exist(c[0])))
			return (0);
	}
	return (1);
}
