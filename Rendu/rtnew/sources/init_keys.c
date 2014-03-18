/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 16:52:29 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/05 14:47:20 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

static t_key	get_key_event(int keycode, key_event *event)
{
	t_key	key;

	key.keycode = keycode;
	key.is_press = 0;
	key.event = event;
	return (key);
}

void			init_events(t_env *e)
{
	e->key_events[0] = get_key_event(ESC, &key_event_esc);
	e->key_events[1] = get_key_event(KEY_S, &key_event_save);
}
