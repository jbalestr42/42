/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:14:30 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/14 17:03:24 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			main(int argc, char **argv)
{
	t_graph	*graph;

	printf("print the map\n");
	printf("print ERROR if the map can't be resolved\n");
	printf("keep going if we found an error and try to resolve\n");
	if (argc == 2)
	{
		if (!(graph = read_map(argv[1])))
			return (0);
		dijkstra(graph);
		//TODO free
	}
	else
		printf("Usage: ./lemin map\n");
	return 0;
}
