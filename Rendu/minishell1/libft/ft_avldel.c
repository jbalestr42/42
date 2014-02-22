/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avldel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:49:15 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/15 13:49:21 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_avldel(t_avl **head, void (*del)(void *, size_t))
{
	t_avl	*tmp;

	tmp = *head;
	if (tmp)
	{
		ft_avldel(&tmp->left, del);
		ft_avldel(&tmp->right, del);
		(*del)(tmp->content, tmp->content_size);
		free(tmp);
		*head = NULL;
	}
}
