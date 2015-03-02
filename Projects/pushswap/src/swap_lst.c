/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 16:19:00 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/28 19:04:36 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>

static int		swap(t_lst *(*head))
{
	int		tmp;

	if ((*head))
	{
		if (((*head))->next)
		{
			tmp = (*head)->val;
			(*head)->val = (*head)->next->val;
			(*head)->next->val = tmp;
			return (1);
		}
	}
	return (0);
}

void			swap_s(t_lst **l_a, t_lst **l_b)
{
	int		i;

	i = swap(l_a) + swap(l_b);
	if (i == 3)
		write(1, "ss ", 3);
	else if (i == 2)
		write(1, "sa ", 3);
	else if (i == 1)
		write(1, "sb ", 3);
}

int				swap_a(t_lst **l_a)
{
	if (swap(l_a))
	{
		write(1, "sa ", 3);
		return (2);
	}
	return (0);
}

int				swap_b(t_lst **l_b)
{
	if (swap(l_b))
	{
		write(1, "sb ", 3);
		return (1);
	}
	return (0);
}
