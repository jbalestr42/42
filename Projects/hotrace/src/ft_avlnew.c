/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:36:18 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/15 13:40:09 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"
#include <stdlib.h>

t_pair		*ft_avlnew(char *key)
{
	t_pair		*leaf;

	leaf = (t_pair *)malloc(sizeof(t_pair));
	leaf->key = ft_strdup(key);
	leaf->value = NULL;
	leaf->left = NULL;
	leaf->right = NULL;
	return (leaf);
}
