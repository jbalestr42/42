/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avliter_inorderrev.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:50:13 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/15 13:50:18 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_avliter_inorderrev(t_avl *head, void (*f)(t_avl *node))
{
	if (!head)
		return ;
	ft_avliter_inorderrev(head->right, f);
	(*f)(head);
	ft_avliter_inorderrev(head->left, f);
}
