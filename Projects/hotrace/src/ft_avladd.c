/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avladd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 07:40:37 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/15 13:40:20 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

static t_pair	*right_right_rotation(t_pair *parent)
{
	t_pair	*tmp;

	tmp = parent->right;
	parent->right = tmp->left;
	tmp->left = parent;
	return (tmp);
}

static t_pair	*left_left_rotation(t_pair *parent)
{
	t_pair	*tmp;

	tmp = parent->left;
	parent->left = tmp->right;
	tmp->right = parent;
	return (tmp);
}

static int		get_diff(t_pair *node)
{
	int		left_height;
	int		right_height;

	left_height = ft_avlheight(node->left);
	right_height = ft_avlheight(node->right);
	return (left_height - right_height);
}

static t_pair	*balancing(t_pair *node)
{
	int		diff;
	t_pair	*tmp;

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

t_pair			*ft_avladd(t_pair *head, char *key, t_pair **leaf)
{
	int			cmp;

	if (head == NULL)
	{
		*leaf = ft_avlnew(key);
		return (*leaf);
	}
	cmp = ft_strcmp(key, head->key);
	if (cmp == 0)
	{
		*leaf = head;
		return (head);
	}
	if (cmp < 0)
	{
		head->left = ft_avladd(head->left, key, leaf);
		head = balancing(head);
	}
	else if (cmp > 0)
	{
		head->right = ft_avladd(head->right, key, leaf);
		head = balancing(head);
	}
	return (head);
}
