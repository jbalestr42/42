/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 12:55:37 by jbalestr          #+#    #+#             */
/*   Updated: 2013/11/30 12:56:20 by jbalestr         ###   ########.fr       */
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
