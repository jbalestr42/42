/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvincent <pvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/18 19:11:14 by pvincent          #+#    #+#             */
/*   Updated: 2014/06/18 19:13:26 by pvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sh.h>

int					ft_open_redir(t_bloc *bloc, char *file)
{
	if (bloc->redir == CLEFT)
	{
		if ((bloc->fd = open(file, O_RDONLY)) == -1)
		{
			perror("42sh");
			return (0);
		}
	}
	else if (bloc->redir == CRIGHT)
	{
		if ((bloc->fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644)) == -1)
		{
			perror("42sh");
			return (0);
		}
	}
	else if (bloc->redir == CDRIGHT)
	{
		if ((bloc->fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644)) == -1)
		{
			perror("42sh");
			return (0);
		}
	}
	return (1);
}
