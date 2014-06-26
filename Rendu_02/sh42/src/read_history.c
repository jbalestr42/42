/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 14:56:31 by jbalestr          #+#    #+#             */
/*   Updated: 2014/06/26 15:01:05 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sh.h>
#include <fcntl.h>

int				init_history(t_data *data)
{
	int			fd;
	int			i;
	char		buf[1];
	t_char		*begin_char;

	i = -1;
	begin_char = NULL;
	data->history = new_line(NULL);
	data->last = data->history;
	if ((fd = open(".history", O_CREAT | O_RDONLY, 0666)) == -1)
		return (0);
	while (read(fd, buf, 1))
	{
		if (*buf == '\n')
		{
			add_list_line(&data->history, new_line(begin_char));
			begin_char = NULL;
			i = 0;
		}
		else
			add_list_char(&begin_char, new_char(*buf), ++i);
	}
	close(fd);
	return (1);
}

int				save_history(t_data *data)
{
	int			fd;
	t_char		*tmp;
	t_line		*history;

	if ((fd = open(".history", O_CREAT | O_WRONLY | O_TRUNC)) == -1)
		return (0);
	history = data->last;
	while (history && history->prev)
		history = history->prev;
	while (history)
	{
		tmp = history->line;
		if (tmp)
		{
			while (tmp)
			{
				write(fd, &tmp->c, 1);
				tmp = tmp->next;
			}
			write(fd, "\n", 1);
		}
		history = history->next;
	}
	close(fd);
	return (1);
}
