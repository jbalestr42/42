/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 14:03:24 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/30 14:03:25 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			tputll(t_data *data)
{
	int			i;
	t_winsize	win;
	t_word		*tmp;

	i = 0;
	tmp = curword(data);
	i = 0;
	ioctl(0, TIOCGWINSZ, &win);
	tputs(tgetstr("mr", NULL), 1, tputchar);
	tputs(tgoto(tgetstr("cm", NULL), 0, win.ws_row), 1, tputchar);
	if (ft_strlen(tmp->str) <= win.ws_col - 6)
		tputstr(tmp->str);
	else
	{
		tputcutstr(tmp->str, win.ws_col - 6);
		write(isatty(1), " ", 1);
	}
	while (i < win.ws_col - tmp->size - 5 && (i++ + 1))
		write(isatty(1), " ", 1);
	tputnbr(data->cpage);
	tputchar('/');
	tputnbr(data->tpage);
	tputs(tgetstr("me", NULL), 1, tputchar);
}

void			display(t_data *data)
{
	int			i;
	int			x;
	int			y;
	t_word		*tmp;

	if (wsize(data))
		tputstr("Window scale is too small");
	else
	{
		tmp = data->words;
		i = -1;
		while (++i != (data->cpage - 1) * data->maxwpp)
			tmp = tmp->next;
		while (i < data->size && i < (data->cpage) * data->maxwpp)
		{
			x = (i / data->maxl) % data->maxc * (data->colwid + 1);
			y = i % data->maxl;
			tputs(tgoto(tgetstr("cm", NULL), x, y), 1, tputchar);
			tputword(tmp->und, tmp->sel, tmp->str);
			tmp = tmp->next;
			i++;
		}
		tputll(data);
	}
}

int				main(int argc, char **argv)
{
	t_data		*data;

	data = datast();
	if (argc == 1)
		return (error(1, USAGE, NULL));
	if (tgetent(data->buffer, getenv("TERM")) < 1)
		return (error(0, EMPTY, NULL));
	signal(SIGINT, sigctrlc);
	signal(SIGCONT, sigfg);
	signal(SIGSEGV, sigsegv);
	signal(SIGTSTP, sigctrlz);
	signal(SIGWINCH, sigwinch);
	init(argc, argv, data);
	ft_select(data);
	return (0);
}
