/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:06:32 by hjeannin          #+#    #+#             */
/*   Updated: 2014/01/06 22:19:29 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		i;

	i = 0;
	if ((s2 = (char *)malloc(sizeof(*s2) * ft_strlen(s1) + 1)))
	{
		while (s1[i] != '\0')
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}
