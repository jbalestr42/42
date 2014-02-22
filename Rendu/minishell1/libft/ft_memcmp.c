/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 01:47:17 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/29 20:45:28 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n && *((unsigned char *)s1) == *((unsigned char *)s2))
		return (ft_memcmp(s1 + 1, s2 + 1, n - 1));
	if (n)
		return (*((unsigned char *)s1) - *((unsigned char *)s2));
	return (0);
}
