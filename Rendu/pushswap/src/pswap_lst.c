/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 17:47:37 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/28 18:03:12 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <unistd.h>
#include <stdlib.h>

static void		pswap(t_lst **l_a, t_lst **l_b)
{
	t_lst	*tmp;

	tmp = *l_b;
	*l_b = (*l_b)->next;
	tmp->next = NULL;
	lst_pushfront(l_a, tmp);
}

void			pswap_a(t_lst **l_a, t_lst **l_b)
{
	if (*l_b)
	{
		pswap(l_a, l_b);
		write(1, "pa ", 3);
	}
}

void			pswap_b(t_lst **l_a, t_lst **l_b)
{
	if (*l_a)
	{
		pswap(l_b, l_a);
		write(1, "pb ", 3);
	}
}
