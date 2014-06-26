/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/14 15:46:44 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/14 17:01:43 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			ft_get_redir(char *cmd)
{
	int		i;
	int		redir;

	i = 0;
	while (cmd[i])
	{
		if ((redir = ft_check_redir(cmd, &i)) != -1)
			return (redir);
		i++;
	}
	return (-1);
}
