/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:11:02 by hjeannin          #+#    #+#             */
/*   Updated: 2014/01/06 22:09:58 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*bc;

	bc = b;
	while (len--)
		*bc++ = (unsigned char)c;
	return (b);
}
