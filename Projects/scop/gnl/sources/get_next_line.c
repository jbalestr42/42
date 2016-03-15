/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 10:55:36 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/11 10:57:05 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static int	has_line(t_buf *buf, int *count)
{
	*count = 0;
	while (buf && buf->c != '\n' && buf->c != '\0')
	{
		(*count)++;
		buf = buf->next;
	}
	return (buf ? 1 : 0);
}

static int	save_chars(t_buf **first, char *tmp)
{
	t_buf	*buf;

	if (*tmp && *first == NULL)
	{
		if ((*first = (t_buf *)malloc(sizeof(t_buf))) == NULL)
			return (-1);
		(*first)->c = *tmp;
		(*first)->next = NULL;
		tmp++;
	}
	buf = *first;
	while (buf->next)
		buf = buf->next;
	while (*tmp)
	{
		if ((buf->next = (t_buf *)malloc(sizeof(t_buf))) == NULL)
			return (-1);
		buf = buf->next;
		buf->c = *tmp;
		buf->next = NULL;
		tmp++;
	}
	return (0);
}

static int	read_line(t_buf **buf, int fd)
{
	char	tmp[BUFF_SIZE + 1];
	char	*nl;
	int		status;

	nl = NULL;
	status = BUFF_SIZE;
	while (!nl && status == BUFF_SIZE)
	{
		ft_bzero(tmp, BUFF_SIZE + 1);
		status = read(fd, tmp, BUFF_SIZE);
		if (status > 0 && save_chars(buf, tmp) == -1)
			return (-1);
		nl = ft_strchr(tmp, '\n');
	}
	return (status);
}

static int	write_line(t_buf **first, char **line, int count)
{
	t_buf	*prev;
	t_buf	*buf;
	int		i;

	if ((*line = (char *)malloc((sizeof(char) * count) + 1)) == NULL)
		return (-1);
	(*line)[count] = '\0';
	i = 0;
	buf = (*first);
	while (buf && i != count)
	{
		(*line)[i] = buf->c;
		prev = buf;
		buf = buf->next;
		free(prev);
		i++;
	}
	if (buf)
	{
		*first = buf->next;
		free(buf);
	}
	else
		*first = NULL;
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static t_buf	*data[256] = {NULL};
	t_buf			**buf;
	int				count;
	int				status;

	if (fd < 0 || fd >= 256 || BUFF_SIZE < 1 || BUFF_SIZE >= 65635 || !line)
		return (-1);
	buf = &(data[fd]);
	if (!has_line(*buf, &count))
	{
		status = read_line(buf, fd);
		if (status < 0)
			return (-1);
		if (status == 0 && *buf == NULL)
			return (0);
	}
	has_line(*buf, &count);
	return (write_line(buf, line, count));
}
