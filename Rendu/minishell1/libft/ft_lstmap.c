/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 00:48:49 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/03 23:59:27 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*tmp;

	tmp = NULL;
	if (!lst || !(*f))
		return (NULL);
	while (lst)
	{
		ft_lstpushback(&tmp, f(lst));
		lst = lst->next;
	}
	return (tmp);
}
