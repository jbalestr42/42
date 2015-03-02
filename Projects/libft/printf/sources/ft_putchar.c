/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:30:17 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/22 16:40:56 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putnchar(char c, int n)
{
	int		i;

	i = -1;
	while (++i < n)
		write(1, &c, 1);
	return (n);
}

int		parse_char(va_list ap, const char *s, int offset)
{
	(void)s;
	(void)offset;
	return (ft_putchar(va_arg(ap, int)));
}

int		parse_percent(va_list ap, const char *s, int offset)
{
	(void)s;
	(void)offset;
	(void)ap;
	return (ft_putchar('%'));
}

int		parse_z(va_list ap, const char *s, int offset)
{
	(void)s;
	(void)offset;
	(void)ap;
	return (ft_putchar('Z'));
}
