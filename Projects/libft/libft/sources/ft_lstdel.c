/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 07:12:44 by jbalestr          #+#    #+#             */
/*   Updated: 2013/11/28 01:30:55 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*node;
	t_list	*tmp;

	node = *alst;
	if (alst && *alst && (*del))
	{
		while (node)
		{
			tmp = node;
			node = node->next;
			(*del)(tmp->content, tmp->content_size);
			free(tmp);
		}
		*alst = NULL;
	}
}
