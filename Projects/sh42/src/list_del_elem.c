/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_del_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:30:15 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/25 23:28:59 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <d_list_tools.h>
#include <stddef.h>

static void		ft_del_elem(t_elem *del_elem)
{
	if (del_elem->next)
		del_elem->next->prev = del_elem->prev;
	if (del_elem->prev)
		del_elem->prev->next = del_elem->next;
	ft_list_clear_elem(del_elem);
}

t_list			*ft_list_del_elem(t_list *current_list, t_elem *del_elem)
{
	if (!current_list)
		return (NULL);
	if (current_list->begin == del_elem)
	{
		current_list->begin = current_list->begin->next;
		if (current_list->begin)
			current_list->begin->prev = NULL;
		if (current_list->begin == current_list->end)
			current_list->end = NULL;
		ft_list_clear_elem(del_elem);
	}
	else if (current_list->end == del_elem)
	{
		current_list->end = current_list->end->prev;
		current_list->end->next = NULL;
		if (current_list->end == current_list->begin)
			current_list->end = NULL;
		ft_list_clear_elem(del_elem);
	}
	else
		ft_del_elem(del_elem);
	current_list->size--;
	return (current_list);
}
