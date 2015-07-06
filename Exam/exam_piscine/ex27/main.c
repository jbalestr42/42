/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/05 19:02:19 by exam              #+#    #+#             */
/*   Updated: 2013/10/05 19:22:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUF_SIZE	1024

char	**check_line(char **map, char *curr, int line, int c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * (line + 2));
	while (i < line)
	{
		j = 0;
		tab[i] = (char*)malloc(sizeof(char) * (c + 1));
		while (j < c)
		{
			tab[i][j] = map[i][j];
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	j = 0;
	while (j < c)
	{
		tab[i][j] = curr[j];
		j++;
	}
	tab[i][j] = '\0';
	tab[++i] = '\0';
	return (tab);
}

void	ft_read(char *path)
{
	int		fd;
	int		rd;
	int		line;
	char	buf[BUF_SIZE];
	char	**map;

	fd = open(path, O_RDONLY);
	while ((rd = read(fd, buf, BUF_SIZE)))
	{
		buf[rd] = '\0';
		map = check_line(map, buf, line++, rd);
	}
}

int		main(int argc, char **argv)
{
	if (argc > 1)
		ft_read(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
