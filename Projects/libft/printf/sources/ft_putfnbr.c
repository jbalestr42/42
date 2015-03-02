/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 23:08:46 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/22 16:42:31 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putfnbr(double n, int prec)
{
	int			count;
	double		nb_prec;
	double		mult;

	mult = 1;
	count = prec;
	while (prec--)
		mult *= 10;
	nb_prec = mult * n;
	count += ft_putnbr(n);
	count += ft_putchar('.');
	nb_prec = nb_prec < 0 ? -nb_prec : nb_prec;
	ft_putnbr((int)nb_prec % (int)mult);
	if (ft_intlen(nb_prec) < prec)
		ft_putnchar('0', ft_intlen(nb_prec) - prec);
	return (count);
}

int		parse_fnbr(va_list ap, const char *s, int offset)
{
	(void)s;
	(void)offset;
	return (ft_putfnbr(va_arg(ap, double), 6));
}
