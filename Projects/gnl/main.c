/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 19:38:12 by jbalestr          #+#    #+#             */
/*   Updated: 2013/12/15 02:56:53 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*s;
	int		ret;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	s = NULL;
	ret = 0;
	while ((ret = get_next_line(fd, &s) > 0))
	{
		ft_putendl(s);
		free(s);
		s = NULL;
	}
	close(fd);
	return (0);
}
