/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 04:04:55 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/21 13:27:45 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_uint_to_base(unsigned int n, int base)
{
	char	tab[] = { "0123456789abcdef" };
	int		count;

	count = 1;
	if (n / base > 0)
		count += ft_uint_to_base(n / base, base);
	ft_putchar(tab[n % base]);
	return (count);
}

int		ft_uint_to_base_upper(unsigned int n, int base)
{
	char	tab[] = { "0123456789ABCDEF" };
	int		count;

	count = 1;
	if (n / base > 0)
		count += ft_uint_to_base_upper(n / base, base);
	ft_putchar(tab[n % base]);
	return (count);
}

int		ft_luint_to_base(long unsigned int n, int base)
{
	char	tab[] = { "0123456789abcdef" };
	int		count;

	count = 1;
	if (n / base > 0)
		count += ft_luint_to_base(n / base, base);
	ft_putchar(tab[n % base]);
	return (count);
}

int		ft_luint_to_base_upper(long unsigned int n, int base)
{
	char	tab[] = { "0123456789ABCDEF" };
	int		count;

	count = 1;
	if (n / base > 0)
		count += ft_luint_to_base(n / base, base);
	ft_putchar(tab[n % base]);
	return (count);
}
