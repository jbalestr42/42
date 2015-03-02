/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 11:55:09 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/22 17:11:37 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <unistd.h>

t_pos		eval_dist(t_surface *s)
{
	t_pos	pos;

	(void)s;
	return (pos);
}

void		filler(t_data *d)
{
	write(1, "5 4\n", 4);
	(void)d;
}
