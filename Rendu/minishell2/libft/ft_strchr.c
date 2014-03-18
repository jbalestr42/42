/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:28:35 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/23 14:28:37 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	if (*s == (char)c)
		return ((char *)s);
	if (!*s)
		return (NULL);
	return (ft_strchr(++s, c));
}
