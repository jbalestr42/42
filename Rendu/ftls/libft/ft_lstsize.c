/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 12:44:06 by jbalestr          #+#    #+#             */
/*   Updated: 2013/11/30 12:53:57 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *begin)
{
	t_list	*node;
	int		i;

	i = 0;
	node = begin;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
