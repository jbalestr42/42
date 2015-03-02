/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:37:04 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/29 16:14:30 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>
#include <unistd.h>

static int		rrotate(t_lst **head)
{
	t_lst	*tmp;
	t_lst	*prev;

	tmp = *head;
	if (tmp && tmp->next)
	{
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
		tmp->next = *head;
		*head = tmp;
		return (1);
	}
	return (0);
}

int			rrotate_r(t_lst **l_a, t_lst **l_b)
{
	write(1, "rrr ", 4);
	return (rrotate(l_a) + rrotate(l_b));
}

int			rrotate_a(t_lst **l_a)
{
	write(1, "rra ", 4);
	return (rrotate(l_a));
}

int			rrotate_b(t_lst **l_b)
{
	write(1, "rrb ", 4);
	return (rrotate(l_b));
}
