/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:25:37 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/20 17:25:57 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <d_list_tools.h>
#include <libft.h>

void		ft_list_print(t_list *list)
{
	t_elem		*tmp;

	if (list)
	{
		tmp = list->begin;
		while (tmp)
		{
			ft_putendl(tmp->data);
			tmp = tmp->next;
		}
	}
}
