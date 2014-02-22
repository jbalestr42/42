/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:51:23 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/15 13:51:29 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **begin)
{
	t_list	*head;
	t_list	*tmp;
	t_list	*tmp1;

	head = *begin;
	tmp = NULL;
	while (head != NULL)
	{
		tmp1 = tmp;
		tmp = head;
		head = head->next;
		tmp->next = tmp1;
	}
	*begin = tmp;
}
