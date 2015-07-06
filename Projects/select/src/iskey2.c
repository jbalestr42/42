/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iskey2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 14:03:21 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/30 14:03:23 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		is_prevp(t_data *data, char *key)
{
	t_word	*tmp;
	int		a;
	int		b;
	int		c;

	if (key[0] == 27 && key[1] == '[' && key[2] == '5' && key[3] == '~')
	{
		a = data->current;
		b = data->maxwpp;
		c = data->tpage;
		tmp = curword(data);
		tmp->und = 0;
		data->current = (a - (a % b) + (c - 1) * b) % (b * c);
		tmp = curword(data);
		tmp->und = 1;
	}
}

void		is_nextp(t_data *data, char *key)
{
	t_word	*tmp;
	int		a;
	int		b;
	int		c;

	if (key[0] == 27 && key[1] == '[' && key[2] == '6' && key[3] == '~')
	{
		a = data->current;
		b = data->maxwpp;
		c = data->tpage;
		tmp = curword(data);
		tmp->und = 0;
		data->current = (a - (a % b) + (c + 1) * b) % (b * c);
		tmp = curword(data);
		tmp->und = 1;
	}
}

void		is_minus(t_data *data, char *key)
{
	if (key[0] == '-' && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		if (data->colwid > 5)
			data->colwid--;
	}
}

void		is_plus(t_data *data, char *key)
{
	t_winsize	win;

	if (key[0] == '+' && key[1] == 0 && key[2] == 0 && key[3] == 0)
	{
		ioctl(0, TIOCGWINSZ, &win);
		if (data->colwid < win.ws_col - 1)
			data->colwid++;
	}
}
