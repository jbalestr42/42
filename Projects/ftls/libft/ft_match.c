/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 12:14:36 by jbalestr          #+#    #+#             */
/*   Updated: 2013/11/30 12:26:49 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_match(char *s1, char *s2)
{
	if (!*s2 && !*s1)
		return (1);
	else if (!*s1)
	{
		if (*s2 == '*' && ft_match(s1, s2 + 1))
			return (1);
	}
	else if (*s2 == '*')
	{
		if (ft_match(s1, s2 + 1) || ft_match(s1 + 1, s2))
			return (1);
	}
	else if (*s1 == *s2 && ft_match(s1 + 1, s2 + 1))
		return (1);
	return (0);
}
