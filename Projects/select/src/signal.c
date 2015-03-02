/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/30 14:03:31 by jbalestr          #+#    #+#             */
/*   Updated: 2014/04/30 14:03:32 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		sigsegv(int signum)
{
	if (signum == SIGSEGV)
	{
		reinit();
		treset(datast());
		write(2, "Unauthorized action\n", 20);
	}
	exit(-1);
}

void		sigctrlc(int signum)
{
	if (signum == SIGINT)
	{
		reinit();
		treset(datast());
	}
	exit(-1);
}

void		sigctrlz(int signum)
{
	char	cp[2];
	t_data	*data;

	if (signum == SIGTSTP)
	{
		data = datast();
		cp[0] = data->term.c_cc[VSUSP];
		cp[1] = 0;
		tcsetattr(0, 0, &(data->buterm));
		tputs(tgetstr("te", NULL), 1, tputchar);
		tputs(tgetstr("ve", NULL), 1, tputchar);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, cp);
	}
}

void		sigfg(int signum)
{
	t_data	*data;

	if (signum == SIGCONT)
	{
		data = datast();
		tcsetattr(0, 0, &(data->term));
		tputs(tgetstr("ti", NULL), 1, tputchar);
		tputs(tgetstr("vi", NULL), 1, tputchar);
		display(data);
	}
}

void		sigwinch(int signum)
{
	if (signum == SIGWINCH)
	{
		reinit();
		display(datast());
	}
}
