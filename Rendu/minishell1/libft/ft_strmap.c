/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:22:16 by pciavald          #+#    #+#             */
/*   Updated: 2013/11/28 06:19:18 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*r;
	int		i;

	i = 0;
	if (!s || (r = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	while (s[i])
	{
		r[i] = (*f)(s[i]);
		i++;
	}
	r[i] = '\0';
	return (r);
}
