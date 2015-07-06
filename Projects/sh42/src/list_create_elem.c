/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:20:12 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/25 19:17:49 by rdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <d_list_tools.h>
#include <stdio.h>
#include <stdlib.h>

static void		ft_init_bloc(t_bloc *bloc)
{
	bloc->tcmd = NULL;
	bloc->was_redir = -1;
	bloc->redir = -1;
	bloc->fd = -1;
	bloc->cmd = NULL;
	bloc->sep_prev = -1;
	bloc->sep_next = -1;
	bloc->success = -1;
	bloc->cmd_type = -1;
}

t_elem			*ft_list_create_elem(int type)
{
	t_elem	*elem;

	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
	{
		perror("ft_list_create_elem()");
		return (NULL);
	}
	elem->type = type;
	elem->data = NULL;
	elem->bloc = NULL;
	if (type == TYPE_CMD)
	{
		if (!(elem->bloc = (t_bloc *)malloc(sizeof(t_bloc))))
			return (NULL);
		ft_init_bloc(elem->bloc);
	}
	return (elem);
}
