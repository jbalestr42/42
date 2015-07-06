/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/01 13:55:39 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/08 18:33:02 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>
#include "server.h"

static t_client		*new_client(int pid)
{
	t_client	*new;

	if (!(new = (t_client *)malloc(sizeof(t_client))))
		return (NULL);
	new->pid = pid;
	new->current = 0;
	new->receiving = 0;
	new->next = NULL;
	new->words = NULL;
	new->current_word = NULL;
	new->time = clock();
	return (new);
}

static void			push_client(t_client **begin, t_client *new)
{
	t_client	*tmp;

	if (!*begin)
		*begin = new;
	else
	{
		tmp = *begin;
		if (!new)
			return ;
		new->next = tmp;
		*begin = new;
	}
}

t_word				*new_word(char c)
{
	t_word			*new;

	if (!(new = (t_word *)malloc(sizeof(t_word))))
		return (NULL);
	new->c = c;
	new->next = NULL;
	return (new);
}

void				push_word(t_client *client, t_word *new)
{
	if (!client->words)
	{
		client->words = new;
		client->current_word = client->words;
	}
	else
	{
		client->current_word->next = new;
		client->current_word = client->current_word->next;
	}
}

t_client			*find_client(t_client **begin, int pid)
{
	t_client	*tmp;

	tmp = *begin;
	while (tmp)
	{
		if (tmp->pid == pid)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = new_client(pid);
	push_client(begin, tmp);
	return (tmp);
}

// Del client del_client(int pid)
