/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 00:16:19 by pciavald          #+#    #+#             */
/*   Updated: 2013/11/22 00:16:20 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char	*ss1;

	ss1 = (char *)s1;
	while (n--)
		*ss1++ = *((unsigned char *)s2++);
	return (s1);
}
