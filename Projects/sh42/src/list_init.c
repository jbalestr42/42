/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:32:49 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/20 17:33:18 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <d_list_tools.h>

t_list		*ft_list_init(t_list *list)
{
	t_elem	*del;
	t_elem	*elem;

	if (list)
	{
		elem = list->begin;
		while (elem)
		{
			del = elem;
			elem = elem->next;
			if (!(list = ft_list_del_elem(list, del)))
				return (0);
		}
	}
	return (list);
}
