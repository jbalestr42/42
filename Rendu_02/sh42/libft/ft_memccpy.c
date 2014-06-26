/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:04:17 by hjeannin          #+#    #+#             */
/*   Updated: 2013/11/28 14:05:21 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*s1c;
	char		*s2c;

	s1c = (char *)s1;
	s2c = (char *)s2;
	while (n--)
	{
		*s1c = *s2c;
		if (*s2c == c)
		{
			return ((char *)s1c + 1);
		}
		s1c++;
		s2c++;
	}
	return (NULL);
}
