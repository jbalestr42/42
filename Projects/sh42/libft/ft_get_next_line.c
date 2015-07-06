/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjeannin <hjeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 23:49:32 by hjeannin          #+#    #+#             */
/*   Updated: 2014/06/25 18:54:48 by hjeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_read_next_buf(int const fd, int *i, ssize_t *ret, char *buf)
{
	if (*i == *ret)
	{
		*i = 0;
		*ret = read(fd, buf, BUFF_SIZE);
		if (*ret == 0)
			return (1);
		if (*ret < 0)
			return (-1);
	}
	return (0);
}

static char		*ft_strjoin_free(char *s, char const *s2)
{
	char				*str;
	size_t				i;
	size_t				j;
	size_t				len;

	i = 0;
	j = 0;
	len = ft_strlen(s) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(*str) * len + 1)))
		return (NULL);
	if (s == NULL || s2 == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	free(s);
	str[i + j] = '\0';
	return (str);
}

int				ft_get_next_line(int const fd, char **line)
{
	size_t				k;
	static int			i = 0;
	static ssize_t		ret = 0;
	static char			buf[BUFF_SIZE];

	k = 0;
	*line = ft_memalloc(BUFF_SIZE);
	if ((ft_read_next_buf(fd, &i, &ret, &(*buf))) == 1)
		return (0);
	while (i < ret && buf[i] != '\n')
	{
		(*line)[k++] = buf[i++];
		(*line) = ft_strjoin_free((*line), buf);
		if ((ft_read_next_buf(fd, &i, &ret, &(*buf))) == 1)
		{
			(*line)[k] = '\0';
			return (1);
		}
	}
	(*line)[k] = '\0';
	if (buf[i] == '\n')
		i++;
	return (1);
}
