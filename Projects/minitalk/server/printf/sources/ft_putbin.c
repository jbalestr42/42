/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 06:10:17 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/22 16:41:23 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putbin(unsigned int n)
{
	return (ft_uint_to_base((unsigned int)n, 2));
}

int		parse_bin(va_list ap, const char *s, int offset)
{
	(void)s;
	(void)offset;
	return (ft_putbin(va_arg(ap, unsigned int)));
}
