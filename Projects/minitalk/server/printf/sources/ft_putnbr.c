/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:34:02 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/22 17:39:26 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr(int n)
{
	int		count;

	count = 1;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		count++;
	}
	if (n / 10 > 0)
		count += ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
	return (count);
}

int		ft_putunbr(unsigned int n)
{
	int		count;

	count = 1;
	if (n / 10 > 0)
		count += ft_putunbr(n / 10);
	ft_putchar('0' + n % 10);
	return (count);
}

int		parse_nbr(va_list ap, const char *s, int offset)
{
	return (ft_putnbropt(s, offset, va_arg(ap, int)));
}

int		parse_unbr(va_list ap, const char *s, int offset)
{
	unsigned int	i;

	(void)s;
	(void)offset;
	i = va_arg(ap, unsigned int);
	return (ft_putunbr(i));
}
