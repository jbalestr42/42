/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:10:20 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/22 16:43:09 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puthexa(unsigned int n)
{
	return (ft_uint_to_base(n, 16));
}

int		parse_hexa(va_list ap, const char *s, int offset)
{
	(void)s;
	(void)offset;
	return (ft_puthexa(va_arg(ap, unsigned int)));
}

int		ft_puthexaupper(unsigned int n)
{
	return (ft_uint_to_base_upper(n, 16));
}

int		parse_hexaupper(va_list ap, const char *s, int offset)
{
	(void)s;
	(void)offset;
	return (ft_puthexaupper(va_arg(ap, unsigned int)));
}
