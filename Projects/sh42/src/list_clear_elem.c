/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:23:53 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/25 18:40:23 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <d_list_tools.h>
#include <stdlib.h>
#include <sh.h>

void		ft_list_clear_elem(t_elem *elem)
{
	if (elem->data)
		free(elem->data);
	if (elem->bloc)
	{
		if (elem->bloc->cmd)
			free(elem->bloc->cmd);
		ft_free_array(elem->bloc->tcmd);
		free(elem->bloc);
	}
	free(elem);
}
