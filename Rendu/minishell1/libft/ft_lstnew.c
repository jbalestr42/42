/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 05:04:37 by pciavald          #+#    #+#             */
/*   Updated: 2013/11/27 05:04:37 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*node;

	if ((node = (t_list *)malloc(sizeof(*node))) == NULL)
		return (NULL);
	if (content)
	{
		if ((node->content = (void *)malloc(content_size)) == NULL)
			return (NULL);
		node->content = ft_memmove(node->content, content, content_size);
	}
	else
		node->content = NULL;
	node->content_size = content ? content_size : 0;
	node->next = NULL;
	return (node);
}
