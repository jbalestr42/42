/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:00:30 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/22 16:43:22 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putoctal(unsigned int n)
{
	return (ft_uint_to_base(n, 8));
}

int		parse_octal(va_list ap, const char *s, int offset)
{
	(void)s;
	(void)offset;
	return (ft_putoctal(va_arg(ap, unsigned int)));
}
