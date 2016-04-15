/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 18:53:37 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/02 18:56:10 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		loop_ants(t_print_data *d, t_graph *graph)
{
	while (d->i < graph->ant_count)
	{
		if (d->ants[d->i]->room == 0)
		{
			d->ant_at_end++;
			d->room_valid[d->ants[d->i]->room] = 0;
		}
		else if (d->ants[d->i]->room - 1 >= 0
				&& d->room_valid[d->ants[d->i]->room - 1] == 0)
		{
			d->room_valid[d->ants[d->i]->room - 1] = 1;
			d->room_valid[d->ants[d->i]->room] = 0;
			d->ants[d->i]->room--;
			ft_print_ant(d->ants[d->i]->num,
					graph->room_name[d->path[d->ants[d->i]->room]]);
		}
		d->i++;
	}
}
