/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 07:27:11 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/08 19:12:15 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
/*	t_list	*new;

	new = NULL;
	if (!lst || !(*f))
		return (NULL);
	while (lst)
	{
		ft_lstpushback(&new, (*f)(lst));
		lst = lst->next;
	}
	return (new);*/
	(void)lst;
	(void)(*f);
	return (NULL);
}
