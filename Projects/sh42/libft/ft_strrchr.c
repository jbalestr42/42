/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:12:18 by hjeannin          #+#    #+#             */
/*   Updated: 2014/02/18 16:48:57 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		while (len >= 0)
		{
			if (s[len] == (char)c)
				return (((char *)s + len));
			len--;
		}
	}
	return (NULL);
}
