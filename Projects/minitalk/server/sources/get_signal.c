/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 12:34:29 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/08 19:09:46 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "ft_printf.h"
#include "server.h"

void			signal_usr(int signal, siginfo_t *siginfo, void *context)
{
	t_client	*client;

	(void)context;
	if (siginfo->si_pid == 0)
		return ;
	client = find_client(&get_data()->clients, siginfo->si_pid);
	if (DEBUG)
	{
		ft_printf("pid sender : %i\n", siginfo->si_pid);
		ft_printf("signal : %s\n", (signal == SIGUSR1) ? "SIGUSR1" : "SIGUSR2");
	}
	if (signal == SIGUSR1)
		signal_usr1(client);
	if (signal == SIGUSR2)
		signal_usr2(client);
	client->last = clock();
}

void		set_bit(t_client *client, int val)
{
	client->byte[client->current] = val;
	client->current++;
	if (client->current >= 8)
	{
		add_byte(client);
		client->current = 0;
	}
	kill(client->pid, SIGUSR1);
}

void		signal_usr1(t_client *client)
{
	if (DEBUG)
		ft_printf("signal received from : %i\n", client->pid);
	set_bit(client, 0);
}

void		signal_usr2(t_client *client)
{
	if (DEBUG)
		ft_printf("signal received from : %i\n", client->pid);
	set_bit(client, 1);
}
