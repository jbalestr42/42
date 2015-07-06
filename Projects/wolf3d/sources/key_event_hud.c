/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_hud.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 22:12:06 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 22:35:58 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	key_event_key_1(t_env *e)
{
	e->hud.current_frame = 0;
	e->weapon.current_frame = 0;
}

void	key_event_key_2(t_env *e)
{
	e->hud.current_frame = 1;
	e->weapon.current_frame = 1;
}

void	key_event_key_3(t_env *e)
{
	e->hud.current_frame = 2;
	e->weapon.current_frame = 2;
}

void	key_event_key_4(t_env *e)
{
	e->hud.current_frame = 3;
	e->weapon.current_frame = 3;
}
