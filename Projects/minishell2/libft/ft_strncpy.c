/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:38:59 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/23 14:39:04 by jbalestr         ###   ########.fr       */
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
