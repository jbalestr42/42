/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 20:34:21 by jbalestr          #+#    #+#             */
/*   Updated: 2013/11/24 05:20:57 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cc;

	cc = NULL;
	while (*s)
	{
		if (*s == (char)c)
			cc = (char *)s;
		s++;
	}
	if (*s == (char)c)
		cc = (char *)s;
	return (cc);
}
