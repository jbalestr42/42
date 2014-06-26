/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 14:29:05 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/23 14:29:06 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	if (!*s1 || !*s2 || (unsigned char)*s1 != (unsigned char)*s2)
		return (*s1 - *s2);
	else
		return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}
