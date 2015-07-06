/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 12:15:03 by fcorbel           #+#    #+#             */
/*   Updated: 2014/06/26 15:07:06 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <termcaps.h>
#include <libft.h>
#include <sh.h>

static void		print_char_history(t_char *begin)
{
	while (begin)
	{
		write(1, &begin->c, 1);
		begin = begin->next;
	}
}

static void		print_list_line(t_line *begin)
{
	while (begin && begin->prev)
		begin = begin->prev;
	while (begin && begin->next)
	{
		ft_putnbr(begin->n);
		ft_putchar(' ');
		print_char_history(begin->line);
		write(1, "\n", 1);
		begin = begin->next;
	}
}

int				ft_history(char **c, t_list *envi)
{
	(void)envi;
	if (c[1] != NULL)
	{
		print_list_line(g_data->last);
		tputs(tgetstr("sc", NULL), 1, tputs_char);
	}
	else
	{
		print_list_line(g_data->last);
		tputs(tgetstr("sc", NULL), 1, tputs_char);
	}
	return (1);
}
