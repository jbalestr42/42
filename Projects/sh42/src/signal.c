/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcorbel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/16 17:29:37 by fcorbel           #+#    #+#             */
/*   Updated: 2014/06/26 15:08:27 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <sh.h>
#include "termcaps.h"

void			ft_sigint(void)
{
	tputs(tgetstr("do", NULL), 1, tputs_char);
	tputs(tgetstr("sc", NULL), 1, tputs_char);
	free_line(g_data->last->line);
	g_data->last->line = NULL;
	g_data->cursor = 0;
	g_data->nb_c = 0;
	print_list_char(g_data->last->line, g_data->cursor);
}

void			ft_sigexit(void)
{
	reset_term(&g_data->term);
	free(g_data);
	exit(0);
}

void			ft_sigtstp(void)
{
	char		cp[2];

	cp[0] = g_data->term.c_cc[VSUSP];
	cp[1] = 0;
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
	reset_term(&g_data->term);
}

void			ft_sigcont(void)
{
	init_term(&g_data->term);
	print_list_char(g_data->last->line, g_data->cursor);
}

void			signal_action(int signal)
{
	if (signal == SIGINT || signal == SIGQUIT)
		ft_sigint();
	else if (signal == SIGTERM || signal == SIGHUP || signal == SIGTTIN)
		ft_sigexit();
	else if (signal == SIGTSTP)
		ft_sigtstp();
	else if (signal == SIGCONT)
		ft_sigcont();
	else if (signal == SIGILL || signal == SIGABRT || signal == SIGBUS ||
			signal == SIGSEGV)
		ft_sigexit();
}
