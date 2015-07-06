/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:12:15 by hjeannin          #+#    #+#             */
/*   Updated: 2013/11/30 15:12:22 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_getsize(int n)
{
	size_t			size;

	size = 0;
	if (n == 0)
	{
		size++;
		return (size);
	}
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char				*ft_itoa(int n)
{
	char		*res;
	size_t		size;
	int			neg;

	if (n == -2147483648 && (res = ft_memalloc(12)))
	{
		ft_strcpy(res, "-2147483648");
		return (res);
	}
	size = ft_getsize(n);
	neg = 0;
	if (n < 0 && (neg = 1))
		n = -n;
	res = ft_memalloc(size);
	res[size] = '\0';
	while (size)
	{
		size--;
		res[size] = (char)(n % 10 + 48);
		n = n / 10;
	}
	if (neg == 1)
		res[0] = '-';
	return (res);
}
