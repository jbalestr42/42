/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:30:16 by pciavald          #+#    #+#             */
/*   Updated: 2013/11/20 13:30:17 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	char	*ptr;

	ptr = s1;
	while (n--)
	{
		if (*s2)
			*s1++ = *s2++;
		else
			*s1++ = '\0';
	}
	return (ptr);
}
