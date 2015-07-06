/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_shift_arrows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 11:07:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/06/26 14:04:39 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sh.h>
#include <libft.h>

int				k_shift_left(t_data *data, char key[KEY_LENGTH])
{
	t_char		*tmp;
	int			i;

	if (ft_strcmp(key, "\x1b\x5b\x31\x3b\x32\x44") == 0)
	{
		i = -1;
		tmp = data->last->line;
		while (tmp->next && ++i != data->cursor)
			tmp = tmp->next;
		if (i == data->cursor || tmp->next == NULL)
		{
			while (tmp && tmp->c != ' ' && data->cursor > 0)
			{
				data->cursor--;
				tmp = tmp->prev;
			}
			while (tmp && tmp->prev && (tmp->c == '\t' || tmp->c == ' '))
			{
				data->cursor--;
				tmp = tmp->prev;
			}
		}
		return (1);
	}
	return (0);
}

int				k_shift_right(t_data *data, char key[KEY_LENGTH])
{
	t_char		*tmp;
	int			i;

	if (ft_strcmp(key, "\x1b\x5b\x31\x3b\x32\x43") == 0)
	{
		i = -1;
		tmp = data->last->line;
		while (tmp->next && ++i != data->cursor)
			tmp = tmp->next;
		if (i == data->cursor || tmp->next == NULL)
		{
			while (tmp && tmp->c != ' ' && data->cursor < data->nb_c)
			{
				data->cursor++;
				tmp = tmp->next;
			}
			while (tmp && tmp->next && (tmp->c == '\t' || tmp->c == ' '))
			{
				data->cursor++;
				tmp = tmp->next;
			}
		}
		return (1);
	}
	return (0);
}

int				k_ctrl_d(t_data *data, char key[KEY_LENGTH])
{
	if (ft_strcmp(key, "\x4\0\0\0\0\0") == 0)
	{
		reset_term(&data->term);
		free(data);
		exit(0);
	}
	return (0);
}

int				k_other(t_data *data, char key[KEY_LENGTH])
{
	(void)data;
	if (ft_strcmp(key, "\x6\0\0\0\0\0") == 0
			|| ft_strcmp(key, "\x0b\0\0\0\0\0") == 0
			|| ft_strcmp(key, "\x0c\0\0\0\0\0") == 0)
	{
		return (1);
	}
	return (0);
}
