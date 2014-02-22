/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 11:01:58 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/08 19:13:54 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <time.h>
#include "server.h"
#include "ft_printf.h"

void			print(t_client *tmp)
{
	if (tmp->receiving)
	{
		tmp->receiving = 0;
		print_word(tmp);
	}
}
int				main(void)
{
	t_data		*data;
	t_client	*tmp;

	data = get_data();
	data->pid = getpid();
	ft_printf("PID: %i\n", data->pid);
	sigaction(SIGUSR1, &data->sa, NULL);
	sigaction(SIGUSR2, &data->sa, NULL);
	while (42)
	{
		tmp = data->clients;
		while (tmp)
		{
			tmp->time = clock();
			if (((tmp->time - tmp->last) / CLOCKS_PER_SEC * 1000) > 100)
			{
				if (tmp->words)
					kill(tmp->pid, SIGUSR1);
			}
			print(tmp);
			tmp = tmp->next;
		}
	}
	return (0);
}
