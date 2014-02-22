/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avladd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 04:50:52 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/14 04:50:54 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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

static int		get_diff(t_avl *node)
{
	int		left_height;
	int		right_height;

	left_height = ft_avlheight(node->left);
	right_height = ft_avlheight(node->right);
	return (left_height - right_height);
}

static t_avl	*balancing(t_avl *node)
{
	int		diff;
	t_avl	*tmp;

	diff = get_diff(node);
	if (diff > 1)
	{
		if (get_diff(node->left) > 0)
			node = left_left_rotation(node);
		else
		{
			tmp = node->left;
			node->left = right_right_rotation(tmp);
			node = left_left_rotation(node);
		}
	}
	else if (diff < -1)
	{
		if (get_diff(node->right) > 0)
		{
			tmp = node->right;
			node->right = left_left_rotation(tmp);
		}
		node = right_right_rotation(node);
	}
	return (node);
}

t_avl			*ft_avladd(t_avl *root, t_avl *node, int (*cmp)(void *, void *))
{
	if (root == NULL)
		return (node);
	else if ((*cmp)(node->content, root->content) <= 0)
	{
		root->left = ft_avladd(root->left, node, cmp);
		root = balancing(root);
	}
	else if ((*cmp)(node->content, root->content) > 0)
	{
		root->right = ft_avladd(root->right, node, cmp);
		root = balancing(root);
	}
	return (root);
}
