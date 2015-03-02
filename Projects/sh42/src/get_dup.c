/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdavid <rdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/23 20:15:30 by rdavid            #+#    #+#             */
/*   Updated: 2014/06/23 20:15:30 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sh.h>

void					ft_get_dup(t_bloc *bloc)
{
	if (bloc->was_redir == CLEFT && dup2(bloc->fd, 0) == -1)
		perror("42sh");
	else if (bloc->was_redir == CRIGHT && dup2(bloc->fd, 1) == -1)
		perror("42sh");
	else if (bloc->was_redir == CDRIGHT && dup2(bloc->fd, 1) == -1)
		perror("42sh");
}
