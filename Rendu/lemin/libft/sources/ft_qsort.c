/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 10:40:55 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/01 10:40:56 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_quicksort(char **items, int left, int right)
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
		ft_quicksort(items, left, j);
	if (i < right)
		ft_quicksort(items, i, right);
}
