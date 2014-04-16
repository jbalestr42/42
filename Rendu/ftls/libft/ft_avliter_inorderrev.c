/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avliter_inorderrev.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 20:29:58 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/10 20:46:31 by jbalestr         ###   ########.fr       */
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
