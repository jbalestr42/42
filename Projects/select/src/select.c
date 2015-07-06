/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 14:03:27 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/30 14:03:28 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int					wsize(t_data *data)
{
	t_winsize		win;

	ioctl(0, TIOCGWINSZ, &win);
	data->maxl = win.ws_row - 1;
	data->maxc = win.ws_col / (data->colwid + 1);
	data->maxwpp = data->maxl * data->maxc;
	if (data->maxc)
	{
		data->tpage = (data->size - 1) / data->maxwpp + 1;
		data->cpage = data->current / data->maxwpp + 1;
	}
	else
		return (-1);
	if (data->tpage > 99)
		return (-1);
	return (0);
}

t_data				*datast(void)
{
	static t_data	*data = NULL;

	if (!data)
		data = (t_data *)malloc(sizeof(t_data));
	return (data);
}

t_word				*curword(t_data *data)
{
	t_word			*tmp;
	int				i;

	tmp = data->words;
	i = 0;
	while (i != data->current)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

void				reinit(void)
{
	tputs(tgetstr("te", NULL), 1, tputchar);
	tputs(tgetstr("ti", NULL), 1, tputchar);
	tputs(tgetstr("cl", NULL), 1, tputchar);
}

void				ft_select(t_data *data)
{
	char			key[4];

	while (42)
	{
		reinit();
		display(data);
		key[0] = 0;
		key[1] = 0;
		key[2] = 0;
		key[3] = 0;
		read(0, key, 4);
		is_prevp(data, key);
		is_nextp(data, key);
		is_up(data, key);
		is_plus(data, key);
		is_minus(data, key);
		is_left(data, key);
		is_right(data, key);
		is_down(data, key);
		is_space(data, key);
		if (is_esc(data, key) || is_enter(data, key) || is_del(data, key))
			break ;
	}
}
