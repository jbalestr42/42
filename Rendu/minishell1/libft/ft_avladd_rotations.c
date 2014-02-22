/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avladd_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:46:32 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/15 13:48:57 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_avl	*right_right_rotation(t_avl *parent)
{
	t_avl	*tmp;

	tmp = parent->right;
	parent->right = tmp->left;
	tmp->left = parent;
	return (tmp);
}

static t_avl	*left_left_rotation(t_avl *parent)
{
	t_avl	*tmp;

	tmp = parent->left;
	parent->left = tmp->right;
	tmp->right = parent;
	return (tmp);
}

t_avl	*right_left_rotation(t_avl *parent)
{
	t_avl	*tmp;

	tmp = parent->right;
	parent->right = left_left_rotation(tmp);
	return (right_right_rotation(parent));
}

t_avl	*left_right_rotation(t_avl *parent)
{
	t_avl	*tmp;

	tmp = parent->left;
	parent->left = right_right_rotation(tmp);
	return (left_left_rotation(parent));
}
