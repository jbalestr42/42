/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 13:34:37 by hjeannin          #+#    #+#             */
/*   Updated: 2013/11/28 14:24:53 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	char		*fresh;
	size_t		i;
	size_t		slen;

	if (s == NULL || f == NULL)
		return (NULL);
	slen = ft_strlen(s);
	fresh = ft_memalloc(slen);
	i = 0;
	while (slen--)
	{
		fresh[i] = (*f)(s[i]);
		i++;
	}
	return (fresh);
}
