/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:39:25 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/23 14:39:27 by jbalestr         ###   ########.fr       */
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
