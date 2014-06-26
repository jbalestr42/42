/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:26:46 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/23 14:26:51 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (n)
	{
		if (*((unsigned char *)s) == (unsigned char)c)
			return ((void *)s);
		else
			return (ft_memchr(++s, c, --n));
	}
	return (NULL);
}
