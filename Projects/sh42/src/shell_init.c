/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 21:21:33 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/26 14:54:40 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sh.h>
#include <libft.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

static int		ft_get_res(int parse_res, char *line, t_data *data)
{
	parse_res = ft_parse(line, data);
	if (!parse_res)
		return (0);
	if (parse_res == 1)
	{
		if (!ft_execute_cmds(data))
			return (0);
	}
	return (1);
}

static void		init_tab(char *tab, int len)
{
	int			i;

	i = -1;
	while (++i < len)
		tab[i] = 0;
}

int				ft_shell_init(t_data *data)
{
	char		*line;
	int			parse_res;

	parse_res = 0;
	while (1)
	{
		while (read_keys(data))
			;
		line = data->line;
		data->cmds = NULL;
		if (line)
		{
			if (ft_get_res(parse_res, line, data) == 0)
				return (0);
			free(line);
		}
		ft_list_clear(&data->cmds);
		tputs(tgetstr("sc", NULL), 1, tputs_char);
	}
	return (1);
}

int				read_keys(t_data *data)
{
	char		key[KEY_LENGTH];
	int			i;
	int			res;

	i = -1;
	init_tab(key, KEY_LENGTH);
	clear_line(data);
	print_list_char(data->last->line, data->cursor);
	read(0, key, KEY_LENGTH);
	while (++i < NB_KEYS)
	{
		res = data->keys[i](data, key);
		if (res == 2)
			return (0);
		else if (res == 1)
			return (1);
	}
	while (data->history != data->last && data->history->next)
		data->history = data->history->next;
	add_list_char(&data->last->line, new_char(key[0]), data->cursor);
	data->nb_c++;
	data->cursor++;
	return (1);
}
