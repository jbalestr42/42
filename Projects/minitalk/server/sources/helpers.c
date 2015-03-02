/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 12:26:53 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/08 19:09:43 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "server.h"
#include "ft_printf.h"

t_data			*get_data(void)
{
	static t_data	*data = NULL;

	if (!data)
	{
		if (!(data = (t_data *)malloc(sizeof(t_data))))
			return (NULL);
		data->clients = NULL;
		data->sa.sa_sigaction = signal_usr;
		data->sa.sa_flags = SA_SIGINFO;
	}
	return (data);
}

void			print_word(t_client *client)
{
	t_word		*tmp;
	t_word		*del;

	if (!client || !client->words)
		return ;
	tmp = client->words;
	while (tmp)
	{
		write(1, &tmp->c, 1);
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	client->words = NULL;
	client->current_word = NULL;
}

void			add_byte(t_client *client)
{
	int		i;
	int		c;

	i = O_SIZE;
	c = 0;
	while (--i >= 0)
	{
		c <<= 1;
		if (client->byte[i])
			c |= 1;
	}
	push_word(client, new_word(c));
	if (c == '\n')
		client->receiving = 1;
}
