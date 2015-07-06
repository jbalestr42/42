/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 11:29:47 by hjeannin          #+#    #+#             */
/*   Updated: 2013/11/25 14:45:18 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (s1 != NULL || s2 != NULL)
	{
		i = 0;
		while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
		{
			if ((unsigned char)s1[i] != (unsigned char)s2[i])
			{
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			}
			i++;
		}
	}
	return (0);
}
