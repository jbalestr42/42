/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 13:14:30 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/04 10:40:51 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			main(void)
{
	t_graph	*graph;

	if (!(graph = read_map()))
		return (0);
	dijkstra(graph);
	destroy_graph(graph);
	return (0);
}
