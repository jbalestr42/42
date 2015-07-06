/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlheight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 17:30:56 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/14 07:46:27 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int		ft_avlheight(t_pair *pair)
{
	int		height;
	int		left_height;
	int		right_height;
	int		max;

	height = 0;
	if (pair)
	{
		left_height = ft_avlheight(pair->left);
		right_height = ft_avlheight(pair->right);
		max = (left_height > right_height) ? left_height : right_height;
		height = 1 + max;
	}
	return (height);
}

