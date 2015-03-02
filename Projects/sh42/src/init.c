/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:55:42 by jbalestr          #+#    #+#             */
/*   Updated: 2014/06/26 15:07:20 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sh.h>

int				init(t_data *data)
{
	char		buf_ent[2048];

	init_tab_keys(data);
	if (tgetent(buf_ent, getenv("TERM")) < 1)
		return (0);
	tcgetattr(0, &data->term);
	init_term(&data->term);
	init_history(data);
	data->cursor = 0;
	data->c_y = 0;
	data->nb_c = 0;
	signal(SIGINT, &signal_action);
	signal(SIGHUP, &signal_action);
	signal(SIGQUIT, &signal_action);
	signal(SIGTTIN, &signal_action);
	signal(SIGTERM, &signal_action);
	signal(SIGTSTP, &signal_action);
	signal(SIGCONT, &signal_action);
	signal(SIGILL, &signal_action);
	signal(SIGABRT, &signal_action);
	signal(SIGBUS, &signal_action);
	signal(SIGSEGV, &signal_action);
	return (1);
}

void			init_term(t_term *term)
{
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tputs(tgetstr("ti", NULL), 1, tputs_char);
	tputs(tgetstr("vi", NULL), 1, tputs_char);
	tputs(tgetstr("sc", NULL), 1, tputs_char);
	tcsetattr(0, 0, term);
}

void			reset_term(t_term *term)
{
	term->c_lflag |= ICANON;
	term->c_lflag |= ECHO;
	tputs(tgetstr("te", NULL), 1, tputs_char);
	tputs(tgetstr("ve", NULL), 1, tputs_char);
	tcsetattr(0, 0, term);
	save_history(g_data);
}

void			init_tab_keys(t_data *data)
{
	data->keys[0] = k_up;
	data->keys[1] = k_down;
	data->keys[2] = k_right;
	data->keys[3] = k_left;
	data->keys[4] = k_enter;
	data->keys[5] = k_delete;
	data->keys[6] = k_suppr;
	data->keys[7] = k_home;
	data->keys[8] = k_end;
	data->keys[9] = k_other;
	data->keys[10] = k_ctrl_d;
}
