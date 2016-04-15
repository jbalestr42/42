/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 15:28:58 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/04 10:40:29 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <fcntl.h>
#include <unistd.h>

void		*return_close(int fd)
{
	close(fd);
	return (NULL);
}

t_graph		*read_map(void)
{
	int		fd;
	int		ant_count;
	t_graph	*graph;
	t_room	*rooms;

	rooms = NULL;
	graph = NULL;
	fd = 0;
	if (!(ant_count = read_num_ant(fd)))
		return (return_close(fd));
	if (!(graph = create_graph()))
		return (return_close(fd));
	if (!read_rooms(graph, &rooms, fd))
	{
		destroy_graph(graph);
		return (return_close(fd));
	}
	close(fd);
	graph->ant_count = ant_count;
	return (graph);
}
