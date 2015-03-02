/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 10:40:55 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/16 18:03:55 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_quicksort(char **items, int left, int right)
{
	int		i_j[2];
	char	*x;
	char	*temp;

	i_j[0] = left;
	i_j[1] = right;
	x = items[(i_j[0] + i_j[1]) / 2];
	while (i_j[0] <= i_j[1])
	{
		while (ft_strcmp(items[i_j[0]], x) < 0 && i_j[0] < right)
			i_j[0]++;
		while (ft_strcmp(items[i_j[1]], x) > 0 && i_j[1] > left)
			i_j[1]--;
		if (i_j[0] <= i_j[1])
		{
			temp = ft_strdup(items[i_j[0]]);
			ft_strcpy(items[i_j[0]++], items[i_j[1]]);
			ft_strcpy(items[i_j[1]--], temp);
			free(temp);
		}
	}
	if (left < i_j[1])
		ft_quicksort(items, left, i_j[1]);
	if (i_j[0] < right)
		ft_quicksort(items, i_j[0], right);
}
