/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:13:51 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 11:18:12 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
#include <unistd.h>

static int		ft_strlen(char const *s)
{
	int			len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void			ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n / 10 > 0)
		ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
}

void			ft_putendl(char const *s)
{
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
