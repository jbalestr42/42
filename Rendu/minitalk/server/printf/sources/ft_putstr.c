/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 06:12:46 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/21 15:24:26 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

int		parse_str(va_list ap, const char *s, int offset)
{
	char	*str;

	(void)s;
	(void)offset;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	ft_putstr(str);
	return (ft_strlen(str));
}
