/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/05 17:11:44 by exam              #+#    #+#             */
/*   Updated: 2013/10/05 17:17:06 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr != NULL)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}
