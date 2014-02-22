/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:57:03 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/01 10:59:25 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s2[0])
		return ((char *)(s1));
	while (s1[i])
	{
		if (s1[i] == s2[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		if (!s2[j])
			return ((char *)(s1 + i - j + 1));
		i++;
	}
	return (NULL);
}
