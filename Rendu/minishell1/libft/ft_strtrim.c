/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 21:13:43 by pciavald          #+#    #+#             */
/*   Updated: 2013/12/01 17:01:17 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_is_whitespace(char const c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		len;

	if (!s)
		return (NULL);
	while (*s && ft_is_whitespace(*s))
		s++;
	len = ft_strlen(s) - 1;
	while (len > 0 && s[len] && ft_is_whitespace(s[len]))
		len--;
	return (ft_strsub(s, 0, len + 1));
}