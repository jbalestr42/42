/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:28:43 by hjeannin          #+#    #+#             */
/*   Updated: 2013/11/25 14:45:28 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		s1_size;

	s1_size = ft_strlen(s1);
	if (s1 != NULL || s2 != NULL)
	{
		i = 0;
		while (i < n)
		{
			if (i < (s1_size + 1))
			{
				s1[i] = s2[i];
				i++;
			}
			else
			{
				s1[i] = '\0';
				i++;
			}
		}
	}
	return (s1);
}
