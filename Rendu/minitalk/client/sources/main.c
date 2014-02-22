/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 11:32:12 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/08 19:11:02 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "client.h"

t_data		*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
	{
		if (!(data = (t_data *)malloc(sizeof(t_data))))
			return (NULL);
		data->valid = 0;
		data->server_pid = 0;
	}
	return (data);
}

void		signal_usr1(int signal, siginfo_t *siginfo, void *context)
{
	t_data	*data;

	(void)context;
	data = get_data();
	if (siginfo->si_pid == data->server_pid)
	{
		if (signal == SIGUSR1)
			data->valid = 1;
	}
}

void		char_to_bin(unsigned int c)
{
	int				o_size;
	t_data			*data;

	data = get_data();
	o_size = 0;
	while (o_size < O_SIZE)
	{
		data->valid = 0;
		if (c & 1)
			kill(data->server_pid, SIGUSR2);
		else
			kill(data->server_pid, SIGUSR1);
		c >>= 1;
		o_size++;
		pause();
		usleep(1);
		if (!data->valid)
			return ;
	}
}

void		send_message(char *message)
{
	t_data	*data;

	data = get_data();
	if (data->server_pid)
	{
		while (*message)
		{
			char_to_bin(*message);
			message++;
		}
		char_to_bin('\n');
	}
}

int			main(int argc, char **argv)
{
	struct sigaction	sa;
	t_data				*data;

	data = get_data();
	sa.sa_sigaction = signal_usr1;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc >= 2)
		data->server_pid = ft_atoi(argv[1]);
	if (argc == 3)
		send_message(argv[2]);
	else if (argc == 2)
		check_line();
	return (0);
}
