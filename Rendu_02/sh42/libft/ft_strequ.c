/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:23:22 by hjeannin          #+#    #+#             */
/*   Updated: 2013/11/28 14:19:20 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strequ(char const *s1, char const *s2)
{
	size_t		i;
	size_t		s1len;
	size_t		s2len;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1len == s2len)
	{
		while (s1[i] == s2[i])
		{
			if (i == s1len)
				return (1);
			i++;
		}
	}
	return (0);
}
