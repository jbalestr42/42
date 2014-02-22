/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:29:17 by jbalestr          #+#    #+#             */
/*   Updated: 2013/11/28 01:19:14 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
