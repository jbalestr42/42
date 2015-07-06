/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avliter_inorder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 20:25:52 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/10 20:46:29 by jbalestr         ###   ########.fr       */
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
