/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:00:50 by hjeannin          #+#    #+#             */
/*   Updated: 2013/11/28 14:25:37 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*fresh;
	unsigned int		i;
	size_t				slen;

	if (s == NULL || f == NULL)
		return (NULL);
	slen = ft_strlen(s);
	fresh = ft_memalloc(slen);
	i = 0;
	while (slen--)
	{
		fresh[i] = (*f)(i, s[i]);
		i++;
	}
	return (fresh);
}
