/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 11:39:02 by glasset           #+#    #+#             */
/*   Updated: 2014/03/27 17:18:45 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"

t_lst			*lst_new(void)
{
	t_lst		*tmp;

	tmp = (t_lst *)malloc(sizeof(t_lst));
	if (tmp)
	{
		tmp->fd = -1;
		tmp->next = NULL;
	}
	return (tmp);
}

t_lst			*lst_add(int fd, t_lst *l)
{
	t_lst		*tmp;

	tmp = (t_lst *)malloc(sizeof(t_lst));
	if (tmp && l)
	{
		tmp->fd = fd;
		tmp->next = NULL;
		if (l->next == NULL)
		{
			l->next = tmp;
			return (l);
		}
		tmp->next = l->next;
		l->next = tmp;
		l = tmp;
	}
	return (l);
}

int				free_l(int ret, char *tmp)
{
	if (tmp)
		free(tmp);
	tmp = NULL;
	return (ret);
}
