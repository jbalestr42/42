/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:27:55 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/20 17:28:12 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <d_list_tools.h>
#include <stdlib.h>

void		ft_list_clear(t_list **list)
{
	t_elem		*tmp;
	t_elem		*del;

	if (*list)
	{
		tmp = (*list)->begin;
		while (tmp)
		{
			del = tmp;
			tmp = tmp->next;
			ft_list_clear_elem(del);
		}
		free(*list);
		*list = NULL;
	}
}
