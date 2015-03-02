/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:08:13 by hjeannin          #+#    #+#             */
/*   Updated: 2014/02/18 16:44:38 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s, char const *s2)
{
	char		*str;
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	len = ft_strlen(s) + ft_strlen(s2);
	str = ft_strnew(len);
	if (s == NULL || s2 == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
