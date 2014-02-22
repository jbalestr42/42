/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 20:58:41 by pciavald          #+#    #+#             */
/*   Updated: 2013/11/25 20:58:43 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (!n || (!*s1 && !*s2))
		return (1);
	else if (*s1 == *s2)
		return (ft_strnequ(s1 + 1, s2 + 1, n - 1));
	return (0);
}
