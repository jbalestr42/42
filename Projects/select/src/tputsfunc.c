/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tputsfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 14:03:38 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/30 14:03:39 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		tputcutstr(char *str, int size)
{
	int		i;

	i = 0;
	if (ft_strlen(str) > size)
	{
		while (i < size - 3)
		{
			write(isatty(1), &str[i], 1);
			i++;
		}
		write(isatty(1), "...", 3);
	}
	else
		tputstr(str);
}

void		tputnbr(int nb)
{
	char	str[2];

	str[1] = nb % 10 + '0';
	str[0] = nb / 10 + '0';
	write(isatty(1), str, 2);
}

void		tputword(int underline, int reverse, char *str)
{
	t_data	*data;

	data = datast();
	if (reverse)
		tputs(tgetstr("mr", NULL), 1, tputchar);
	if (underline)
		tputs(tgetstr("us", NULL), 1, tputchar);
	tputcutstr(str, data->colwid);
	tputs(tgetstr("me", NULL), 1, tputchar);
}

void		tputstr(char *str)
{
	write(isatty(1), str, ft_strlen(str));
}

int			tputchar(int c)
{
	write(isatty(1), &c, 1);
	return (1);
}
