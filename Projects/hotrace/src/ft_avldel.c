/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avldel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 17:03:09 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/14 08:03:43 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hotrace.h"

void	ft_avldel(t_pair **head)
{
	t_pair		*tmp;

	tmp = *head;
	if (tmp)
	{
		ft_avldel(&tmp->left);
		ft_avldel(&tmp->right);
		ft_strdel(&tmp->key);
		ft_strdel(&tmp->value);
		free(tmp);
		*head = NULL;
	}
}
