/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 00:56:46 by pciavald          #+#    #+#             */
/*   Updated: 2013/11/22 00:56:47 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	tmp[n];
	char	*s;

	i = 0;
	s = (char *)s1;
	while (i < n)
		tmp[i++] = *((char *)s2++);
	while (i--)
		s[i] = tmp[i];
	return (s1);
}
