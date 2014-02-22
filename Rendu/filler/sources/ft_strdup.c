/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:28:09 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/22 15:13:08 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdlib.h>

char	*ft_strdup(char const *s1)
{
	char	*s2;
	int		len;

	len = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (*s1)
		*s2++ = *s1++;
	*s2 = '\0';
	return (s2 - len);
}
