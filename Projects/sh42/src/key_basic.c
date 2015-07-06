/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 11:01:21 by jbalestr          #+#    #+#             */
/*   Updated: 2014/06/26 15:00:48 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sh.h>
#include <libft.h>
#include <stdlib.h>

int				k_enter(t_data *data, char key[KEY_LENGTH])
{
	if (ft_strcmp(key, "\x0a\0\0\0\0\0") == 0)
	{
		clear_line(data);
		print_list_char(data->last->line, -1);
		while (data->history->next)
			data->history = data->history->next;
		if (count_char(data->last->line) > 0)
			add_list_line(&data->history, new_line(data->last->line));
		data->line = convert_line(data);
		data->last->line = NULL;
		data->cursor = 0;
		data->nb_c = 0;
		tputs(tgetstr("do", NULL), 1, tputs_char);
		tputs(tgetstr("sc", NULL), 1, tputs_char);
		return (2);
	}
	return (0);
}

int				k_home(t_data *data, char key[KEY_LENGTH])
{
	if (ft_strcmp(key, "\x1b\x5b\x48\0\0\0") == 0)
	{
		data->cursor = 0;
		return (1);
	}
	return (0);
}

int				k_end(t_data *data, char key[KEY_LENGTH])
{
	if (ft_strcmp(key, "\x1b\x5b\x46\0\0\0") == 0)
	{
		data->cursor = data->nb_c;
		return (1);
	}
	return (0);
}

int				k_delete(t_data *data, char key[KEY_LENGTH])
{
	if (ft_strcmp(key, "\x1b\x5b\x33\x7e\0\0") == 0)
	{
		if (data->cursor != data->nb_c)
		{
			tputs(tgetstr("#4", NULL), 1, tputs_char);
			remove_char(data, &data->last->line, data->cursor);
		}
		return (1);
	}
	return (0);
}

int				k_suppr(t_data *data, char key[KEY_LENGTH])
{
	if (ft_strcmp(key, "\x7f\0\0\0\0\0") == 0)
	{
		if (remove_char(data, &data->last->line, data->cursor - 1))
		{
			tputs(tgetstr("#4", NULL), 1, tputs_char);
			data->cursor = data->cursor < 0 ? 0 : data->cursor - 1;
		}
		return (1);
	}
	return (0);
}
