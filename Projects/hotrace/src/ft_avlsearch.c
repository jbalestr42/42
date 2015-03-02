/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 11:41:58 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/15 11:59:46 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

void	ft_avlsearch(t_pair *tree, char *key, char **ret)
{
	int		cmp;

	if (tree == NULL)
		return ;
	cmp = ft_strcmp(tree->key, key);
	if (cmp == 0)
	{
		*ret = tree->value;
		return ;
	}
	if (cmp > 0)
		ft_avlsearch(tree->left, key, ret);
	else if (cmp < 0)
		ft_avlsearch(tree->right, key, ret);
}
