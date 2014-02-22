/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 15:43:00 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 18:33:53 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include "gnl.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static char		*ft_strchr(const char *s, int c)
{
	if (*s == (char)c)
		return ((char *)s);
	if (!*s)
		return (NULL);
	return (ft_strchr(++s, c));
}

static int		ft_read_first_line(t_env *e, char *s)
{
	char	*tmp;

	if ((tmp = ft_strchr(s, 'x')))
	{
		e->map_height = ft_atoi(tmp + 1);
		*tmp = '\0';
		e->map_width = ft_atoi(s);
		e->height_px = e->map_height * SIZE;
		e->width_px = e->map_width * SIZE;
		return (1);
	}
	return (0);
}

static void		ft_init_pos(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->map_height)
	{
		j = 0;
		while (j < e->map_width)
		{
			if (e->map[i][j] == SPAWN)
			{
				e->pov.alpha = 180;
				e->pov.pos.x = j * SIZE + SIZE / 2;
				e->pov.pos.y = i * SIZE + SIZE / 2;
			}
			j++;
		}
		i++;
	}
}

static int		ft_read(t_env *e, int fd)
{
	char	*line;
	int		i;

	i = -1;
	line = NULL;
	if (get_next_line(fd, &line))
	{
		if (!ft_read_first_line(e, line))
			return (0);
	}
	e->map = (int **)malloc(sizeof(int *) * e->map_height);
	while (++i < e->map_height)
	{
		get_next_line(fd, &line);
		if (line)
			e->map[i] = ft_intsplit(line, e->map_width);
	}
	ft_init_pos(e);
	return (1);
}

int				init_map(t_env *e, char *path)
{
	int		fd;

	(void)path;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (-1);
	if (!ft_read(e, fd))
		return (-1);
	close(fd);
	return (1);
}
