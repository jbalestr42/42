/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 16:57:40 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/08 17:17:27 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_avl	*ft_avlnew(void const *content, size_t content_size)
{
	t_avl	*node;

	if (!(node = (t_avl *)malloc(sizeof(t_avl))))
		return (NULL);
	if (content)
	{
		if (!(node->content = (void *)malloc(content_size)))
			return (NULL);
		node->content = ft_memmove(node->content, content, content_size);
	}
	else
		node->content = NULL;
	node->content_size = !content ? 0 : content_size;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
