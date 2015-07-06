/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 19:58:25 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/10 17:16:23 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

static int		get_buff(char **line, t_buff **buff)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = (*buff)->index;
	while (i < (*buff)->read)
	{
		if ((*buff)->buf[i] == '\n')
			break ;
		i++;
	}
	tmp = ft_strsub((*buff)->buf, (*buff)->index, i - (*buff)->index);
	tmp2 = *line;
	if (line && *line)
		*line = ft_strjoin(*line, tmp);
	else
		*line = ft_strdup(tmp);
	free(tmp);
	free(tmp2);
	if (i < (*buff)->read)
	{
		(*buff)->index = i + 1;
		return (1);
	}
	return (0);
}

static t_list	*ft_lstfind(t_list *begin, int fd)
{
	t_buff	*buff;

	if (!begin)
		return (NULL);
	while (begin)
	{
		buff = (t_buff *)begin->content;
		if (buff && buff->fd == fd)
			return (begin);
		begin = begin->next;
	}
	return (NULL);
}

static t_list	*get_fd(t_list **begin, int fd)
{
	t_buff	*buff;
	t_list	*tmp;

	if ((tmp = ft_lstfind(*begin, fd)))
		return (tmp);
	if ((buff = (t_buff *)malloc(sizeof(t_buff))) == NULL)
		return (NULL);
	buff->read = 0;
	buff->index = 0;
	buff->fd = fd;
	if (!(tmp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	tmp->content = buff;
	tmp->content_size = sizeof(buff);
	ft_lstadd(begin, tmp);
	return (tmp);
}

static void	ft_lstrm(t_list **begin, int fd)
{
	t_list	*current;
	t_list	*previous;
	t_list	*tmp;

	current = (*begin)->next;
	previous = *begin;
	if (*begin && fd == ((t_buff *)(*begin)->content)->fd)
	{
		tmp = *begin;
		*begin = (*begin)->next;
		free(tmp);
		return ;
	}
	while (current != NULL && previous != NULL)
	{
		if (fd == ((t_buff *)(*begin)->content)->fd)
		{
			tmp = current;
			previous->next = current->next;
			free(tmp);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

int		get_next_line(int const fd, char **line)
{
	static t_list	*begin = NULL;
	t_buff			*buff;

	ft_strdel(line);
	if (BUFF_SIZE == 0 || BUFF_SIZE > MAX_VALUE ||  fd < 0 || line == NULL)
		return (GNL_ERROR);
	if (!(buff = (t_buff *)get_fd(&begin, fd)->content))
		return (GNL_ERROR);
	if (buff->index)
	{
		if (get_buff(line, &buff))
			return (GNL_SUCCESS);
	}
	buff->index = 0;
	while ((buff->read = read(buff->fd, buff->buf, BUFF_SIZE)))
	{
		if (buff->read == -1)
			return (-1);
		if (get_buff(line, &buff))
			return (GNL_SUCCESS);
	}
	ft_lstrm(&begin, fd);
	return (GNL_EOF);
}
