/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlheight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:49:37 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/15 13:49:39 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_avlheight(t_avl *node)
{
	int		height;
	int		left_height;
	int		right_height;
	int		max;

	height = 0;
	if (node != NULL)
	{
		left_height = ft_avlheight(node->left);
		right_height = ft_avlheight(node->right);
		max = (left_height > right_height) ? left_height : right_height;
		height = 1 + max;
	}
	return (height);
}

