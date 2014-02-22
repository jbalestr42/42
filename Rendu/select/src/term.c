/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 17:14:15 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/10 13:49:28 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	flags(t_termios *term)
{
	term->c_lflag ^= ICANON;
	term->c_lflag ^= ECHO;
}

void	reset(t_data *data)
{
	tputs(tgetstr("te", NULL), 1, tputs_putchar);
	tputs(tgetstr("ve", NULL), 1, tputs_putchar);
	flags(&(data->term));
	tcsetattr(0, 0, &(data->term));
	if (data->ret)
	{
		ft_putendl(data->ret);
		ft_strdel(&data->ret);
	}
	free(data->words);
}

void	init(int argc, char **argv, t_data *data)
{
	int			index;

	data->size = argc - 1;
	data->words = (t_word *)malloc(sizeof(t_word) * data->size);
	index = 0;
	while (index < argc - 1)
	{
		data->words[index].sel = 0;
		data->words[index].und = 0;
		data->words[index].size = ft_strlen(argv[index + 1]);
		data->words[index].str = argv[index + 1];
		index++;
	}
	data->words[0].und = 1;
	data->current = 0;
	data->deleted = 0;
	data->ret = NULL;
	tcgetattr(0, &(data->term));
	flags(&(data->term));
	tcsetattr(0, 0, &(data->term));
	tputs(tgetstr("ti", NULL), 1, tputs_putchar);
	tputs(tgetstr("vi", NULL), 1, tputs_putchar);
}

void	term_putstr(int underline, int reverse, char *str)
{
	if (reverse)
		tputs(tgetstr("mr", NULL), 1, tputs_putchar);
	if (underline)
		tputs(tgetstr("us", NULL), 1, tputs_putchar);
	ft_putstr(str);
	if (reverse)
		tputs(tgetstr("me", NULL), 1, tputs_putchar);
	if (underline)
		tputs(tgetstr("ue", NULL), 1, tputs_putchar);
}
