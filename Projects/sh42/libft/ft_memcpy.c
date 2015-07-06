/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:38:44 by hjeannin          #+#    #+#             */
/*   Updated: 2013/11/28 14:06:32 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *s1, const void *s2, size_t n)
{
	char		*s1c;
	char		*s2c;

	s1c = (char *)s1;
	s2c = (char *)s2;
	while (n--)
		*s1c++ = *s2c++;
	return (s1);
}
