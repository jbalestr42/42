/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avliter_inorder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:49:59 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/15 13:50:05 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_avliter_inorder(t_avl *head, void (*f)(t_avl *node))
{
	if (!head)
		return ;
	ft_avliter_inorder(head->left, f);
	(*f)(head);
	ft_avliter_inorder(head->right, f);
}
