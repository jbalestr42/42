/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:27:14 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/20 17:35:10 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <d_list_tools.h>
#include <stddef.h>

t_list		*ft_list_push_back(t_list *list, t_elem *elem)
{
	if (!list)
		return (NULL);
	elem->next = NULL;
	if (list->end == NULL)
	{
		elem->prev = NULL;
		list->begin = elem;
		list->end = elem;
	}
	else
	{
		list->end->next = elem;
		elem->prev = list->end;
		list->end = elem;
	}
	list->size++;
	return (list);
}
