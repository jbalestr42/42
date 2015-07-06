/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:34:17 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/28 21:37:00 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdlib.h>
#include <unistd.h>

static int		rotate(t_lst **head)
{
	t_lst	*tmp;
	t_lst	*first;

	tmp = *head;
	if (tmp && tmp->next)
	{
		first = *head;
		*head = (*head)->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = first;
		first->next = NULL;
		return (1);
	}
	return (0);
}

int			rotate_r(t_lst **l_a, t_lst **l_b)
{
	write(1, "rr ", 3);
	return (rotate(l_a) + rotate(l_b));
}

int			rotate_a(t_lst **l_a)
{
	write(1, "ra ", 3);
	return (rotate(l_a));
}

int			rotate_b(t_lst **l_b)
{
	write(1, "rb ", 3);
	return (rotate(l_b));
}
