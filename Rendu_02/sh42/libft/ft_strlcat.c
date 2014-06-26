/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:47:05 by hjeannin          #+#    #+#             */
/*   Updated: 2013/11/29 15:39:05 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		i;
	size_t		j;
	size_t		destlen;

	i = 0;
	j = 0;
	destlen = ft_strlen(dest);
	if (destlen >= size)
		return (size + ft_strlen(src));
	while (dest[i] != '\0')
		i++;
	while (j < size - destlen - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (destlen + ft_strlen(src));
}
