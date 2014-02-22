/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 13:52:10 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/15 14:50:20 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_qsort(char **items, int left, int right)
{
	int		i;
	int		j;
	char	*x;
	char	*temp;

	x = items[((i = left) + (j = right)) / 2];
	while (i <= j)
	{
		while (ft_strcmp(items[i], x) < 0 && i < right)
			i++;
		while (ft_strcmp(items[j], x) > 0 && j > left)
			j--;
		if (i <= j)
		{
			temp = ft_strdup(items[i]);
			ft_strcpy(items[i++], items[j]);
			ft_strcpy(items[j--], temp);
			free(temp);
		}
	}
	if (left < j)
		ft_qsort(items, left, j);
	if (i < right)
		ft_qsort(items, i, right);
}
