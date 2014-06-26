/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 14:03:11 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/30 14:03:12 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			error(int quit, char *msg, t_data *data)
{
	write(2, msg, ft_strlen(msg));
	if (data)
		treset(data);
	if (quit)
		exit(-1);
	return (-1);
}

void		flags(t_termios *term)
{
	term->c_lflag ^= ICANON;
	term->c_lflag ^= ECHO;
}

void		tinit(t_data *data)
{
	tcgetattr(0, &(data->term));
	tcgetattr(0, &(data->buterm));
	flags(&(data->term));
	tcsetattr(0, 0, &(data->term));
	tputs(tgetstr("ti", NULL), 1, tputchar);
	tputs(tgetstr("vi", NULL), 1, tputchar);
}

void		winit(int argc, char **argv, t_word *word)
{
	t_word	*prev;
	t_word	*current;
	int		i;

	i = 1;
	word->next = word;
	word->sel = 0;
	word->und = 1;
	word->size = ft_strlen(argv[1]);
	word->str = argv[1];
	prev = word;
	while (i < argc - 1)
	{
		current = (t_word *)malloc(sizeof(t_word));
		prev->next = current;
		current->prev = prev;
		current->sel = 0;
		current->und = 0;
		current->size = ft_strlen(argv[i + 1]);
		current->str = argv[i + 1];
		current->next = word;
		prev = current;
		i++;
	}
	word->prev = prev;
}

void		init(int argc, char **argv, t_data *data)
{
	data->size = argc - 1;
	data->words = (t_word *)malloc(sizeof(t_word));
	winit(argc, argv, data->words);
	data->current = 0;
	data->tsel = 0;
	data->cpage = 1;
	data->tpage = 0;
	data->maxl = 0;
	data->maxc = 0;
	data->maxwpp = 0;
	data->colwid = 30;
	tinit(data);
}
