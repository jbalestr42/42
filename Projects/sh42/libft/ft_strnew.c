/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 13:20:55 by hjeannin          #+#    #+#             */
/*   Updated: 2014/01/06 22:24:47 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strnew(size_t size)
{
	size_t		i;
	char		*new;

	i = 0;
	if (size == 0)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(*new) * size + 1)))
		return (NULL);
	while (i <= size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}
