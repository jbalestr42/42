/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:52:12 by hjeannin          #+#    #+#             */
/*   Updated: 2013/11/22 13:54:49 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*sc;
	size_t	i;

	sc = (char *)s;
	i = 0;
	while (i < n)
	{
		if (sc[i] == (char)c)
		{
			return ((void *)sc + i);
		}
		i++;
	}
	return (NULL);
}
