/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 04:11:30 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/06 10:57:52 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strrealloc(char *ptr, size_t size)
{
	char	*str;

	if (!ptr || !size)
		return (NULL);
	str = (char *)malloc(sizeof(char) * size + 1);
	ft_strncpy(str, ptr, size + 1);
	free(ptr);
	return (str);
}
