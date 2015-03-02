/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_arrows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:52:54 by jbalestr          #+#    #+#             */
/*   Updated: 2014/06/26 14:59:47 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <stdlib.h>
#include <sh.h>

int				k_up(t_data *data, char key[KEY_LENGTH])
{
	if (ft_strcmp(key, "\x1b\x5b\x41\0\0\0") == 0)
	{
		if (data->history->prev != NULL)
		{
			clear_line(data);
			data->history = data->history->prev;
			data->nb_c = count_char(data->history->line);
			data->cursor = data->nb_c;
			free_line(data->last->line);
			data->last->line = copy_line(data->history->line);
		}
		return (1);
	}
	return (0);
}

int				k_down(t_data *data, char key[KEY_LENGTH])
{
	if (ft_strcmp(key, "\x1b\x5b\x42\0\0\0") == 0)
	{
		if (data->history->next == data->last)
		{
			clear_line(data);
			data->cursor = 0;
			data->nb_c = 0;
			data->last->line = NULL;
		}
		if (data->history->next != NULL)
		{
			clear_line(data);
			data->history = data->history->next;
			data->nb_c = count_char(data->history->line);
			data->cursor = data->nb_c;
			free_line(data->last->line);
			data->last->line = copy_line(data->history->line);
		}
		return (1);
	}
	return (0);
}

int				k_right(t_data *data, char key[KEY_LENGTH])
{
	if (ft_strcmp(key, "\x1b\x5b\x43\0\0\0") == 0)
	{
		data->cursor = data->cursor >= data->nb_c ?
			data->nb_c : data->cursor + 1;
		return (1);
	}
	return (0);
}

int				k_left(t_data *data, char key[KEY_LENGTH])
{
	if (ft_strcmp(key, "\x1b\x5b\x44\0\0\0") == 0)
	{
		data->cursor = data->cursor == 0 ? 0 : data->cursor - 1;
		return (1);
	}
	return (0);
}
