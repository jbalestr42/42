/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 19:58:59 by pciavald          #+#    #+#             */
/*   Updated: 2013/11/25 19:59:00 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

void	*ft_memalloc(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if ((s = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	while (i < size)
		s[i++] = 0;
	return (s);
}
