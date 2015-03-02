/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:26:55 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/22 16:39:31 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putaddr(long unsigned int p)
{
	int		count;

	ft_putstr("0x");
	count = ft_luint_to_base(p, 16);
	return (count + 2);
}

int		parse_addr(va_list ap, const char *s, int offset)
{
	long unsigned int	p;

	(void)s;
	(void)offset;
	p = va_arg(ap, long unsigned int);
	return (ft_putaddr(p));
}
