/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:48:20 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/12 19:07:31 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		max_len(t_data *data, int i, int max)
{
	int		len;
	int		j;

	j = len = 0;
	while (j < max)
	{
		if ((i + j) < data->size)
			len = data->words[j + i].size > len ? data->words[j + i].size : len;
		j++;
	}
	return (len);
}

t_col	*init_column(t_data *data, int index, t_winsize *win)
{
	t_col	*col;

	if (!(col = (t_col *)malloc(sizeof(t_col))))
		return (NULL);
	col->index = index;
	col->width = max_len(data, index, win->ws_row);
	col->next = NULL;
	return (col);
}

void	ft_putspace(int nb)
{
	int		i;

	i = -3;
	while (++i < nb)
		ft_putstr(" ");
}

int		init_columns(t_data *data, t_winsize *win)
{
	int		index;
	int		nb_col;
	t_col	*tmp;

	index = 0;
	data->columns = init_column(data, index, win);
	tmp = data->columns;
	nb_col = tmp->width;
	while (index < data->size)
	{
		if (nb_col > win->ws_col)
		{
			data->columns->index = 0;
			data->columns->width = 0;
			data->columns->next = NULL;
			if (win->ws_row < data->size + 2)
				return (-1);
			return (1);
		}
		if (index % (win->ws_row - 1) == 0 && index != 0)
		{
			data->columns->next = init_column(data, index, win);
			data->columns = data->columns->next;
			nb_col += data->columns->width;
		}
		index++;
	}
	data->columns = tmp;
	return (1);
}

void	display(t_data *data)
{
	int			index;
	int			jndex;
	t_winsize	win;
	t_word		*word;
	t_col		*tmp;

	ioctl(0, TIOCGWINSZ, &win);
	index = 0;
	jndex = 0;
	if (init_columns(data, &win) == -1)
		term_putstr(0, 0, "Not enough space.\n");
	else
	{
		while (jndex < data->size)
		{
			tmp = data->columns;
			while (tmp)
			{
				if (index + tmp->index < data->size)
				{
					word = &(data->words[index + tmp->index]);
					term_putstr(word->und, word->sel, word->str);
					ft_putspace(tmp->width - word->size);
					jndex++;
				}
				tmp = tmp->next;
			}
			index++;
			term_putstr(0, 0, "\n");
		}
	}
	while (data->columns)
	{
		tmp = data->columns;
		data->columns = data->columns->next;
		free(tmp);
	}
	/*
	   while (index < data->size)
	   {
	   word = &(data->words[index]);
	   if (word->str)
	   {
	   len += ft_strlen(word->str);
	   if (len < win.ws_col)
	   {
	   word = &(data->words[index]);
	   term_putstr(word->und, word->sel, word->str);
	   term_putstr(0, 0, "\n");
	   index++;
	   }
	   else
	   {
	   term_putstr(0, 0, "\n");
	   len = 0;
	   }
	   }
	   else
	   index++;
	   }*/
}

void	sighandler(int signum)
{
	if (signum == SIGSEGV)
	{
		tputs(tgetstr("te", NULL), 1, tputs_putchar);
		tputs(tgetstr("ve", NULL), 1, tputs_putchar);
		ft_putendl("this action is not authorized.");
	}
	exit(-1);
}

int		main(int argc, char **argv)
{
	t_data		data;

	if (argc == 1)
		return (error(1, USAGE, NULL));
	if (tgetent(data.buffer, getenv("TERM")) < 1)
		return (error(0, EMPTY, NULL));
	signal(SIGSEGV, sighandler);
	init(argc, argv, &data);
	ft_select(&data);
	reset(&data);
	return (0);
}
