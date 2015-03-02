/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avldel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 17:03:09 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/08 17:03:41 by jbalestr         ###   ########.fr       */
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
