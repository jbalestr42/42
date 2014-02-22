/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:04:42 by pciavald          #+#    #+#             */
/*   Updated: 2013/11/25 20:04:44 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <libft.h>

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if ((s = ft_memalloc(++size)) == NULL)
		return (NULL);
	while (i < size)
		s[i++] = '\0';
	return (s);
}
