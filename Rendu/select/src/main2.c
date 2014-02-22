/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pciavald <pciavald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 18:03:05 by pciavald          #+#    #+#             */
/*   Updated: 2014/01/03 17:10:25 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int tputs_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int		main(int argc, char **argv, char **envp)
{
	char			buffer[2048];
	t_termios		term;
	char			read_char[4] = {0};

	if (tgetent(buffer, getenv("TERM")) < 1)
		return (-1);
	tcgetattr(0, &term);
	term.c_lflag ^= ICANON; /* each char is treated independently */
	term.c_lflag ^= ECHO; /* prevents a char from being output when pressed*/
	tcsetattr(0, 0, &term);
	tputs(tgetstr("ti", NULL), 1, tputs_putchar); /* opens cup */
	tputs(tgetstr("mr", NULL), 1, tputs_putchar); /* turns on reverse video */
	write(1, "reverse video", 13);
	tputs(tgetstr("me", NULL), 1, tputs_putchar); /* turns off all */
	tputs(tgetstr("do", NULL), 1, tputs_putchar); /* cursor down one line */
	write(1, "normal", 7);
	tputs(tgetstr("do", NULL), 1, tputs_putchar); /* cursor down one line */
	while (read_char[0] == 0)
		read(0, read_char, 3);
	tputs(tgetstr("te", NULL), 1, tputs_putchar); /* closes cup */
	term.c_lflag ^= ICANON;
	term.c_lflag ^= ECHO;
	tcsetattr(0, 0, &term); /* back to default values */
	(void)argc;
	(void)argv;
	(void)envp;
	return (0);
}
