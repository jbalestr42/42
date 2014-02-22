/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 06:23:30 by pciavald          #+#    #+#             */
/*   Updated: 2013/11/27 06:23:30 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*node;
	t_list		*tmp;

	if (!alst || !*alst || !(*del))
		return ;
	node = *alst;
	while (node)
	{
		tmp = node;
		node = node->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
	}
	*alst = NULL;
}
