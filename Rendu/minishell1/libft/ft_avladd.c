/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avladd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:45:20 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/29 20:44:30 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_avladd_rotations.c"
#include <stdlib.h>

static int		get_diff(t_avl *nd)
{
	int		left_height;
	int		right_height;

	left_height = ft_avlheight(nd->left);
	right_height = ft_avlheight(nd->right);
	return (left_height - right_height);
}

static t_avl	*balancing(t_avl *nd)
{
	int		diff;

	diff = get_diff(nd);
	if (diff > 1)
	{
		if (get_diff(nd->left) > 0)
			nd = left_left_rotation(nd);
		else
			nd = left_right_rotation(nd);
	}
	else if (diff < -1)
	{
		if (get_diff(nd->right) > 0)
			nd = right_left_rotation(nd);
		else
			nd = right_right_rotation(nd);
	}
	return (nd);
}

t_avl			*ft_avladd(t_avl *root, t_avl *nd, int (*cmp)(void *, void *))
{
	if (root == NULL)
		return (nd);
	else if ((*cmp)(nd->content, root->content) <= 0)
	{
		root->left = ft_avladd(root->left, nd, cmp);
		root = balancing(root);
	}
	else if ((*cmp)(nd->content, root->content) > 0)
	{
		root->right = ft_avladd(root->right, nd, cmp);
		root = balancing(root);
	}
	return (root);
}
