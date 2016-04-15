/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:10:12 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/18 15:23:02 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>

static t_env	*read_file(char *path, t_env **e)
{
	t_line		*head;
	char		*line;
	int			fd;

	line = NULL;
	head = NULL;
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstpushback(&head, ft_lstnew(line));
		line = NULL;
		(*e)->nb_line++;
	}
	*e = ft_initpoints(*e, &head);
	return (*e);
}

int				main(int argc, char **argv)
{
	t_env	*e;

	if (!(e = ft_envnew()))
		return (EXIT_FAILURE);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fdf");
	if (argc > 1)
		read_file(argv[1], &e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	ft_envdel(e);
	return (EXIT_SUCCESS);
}
