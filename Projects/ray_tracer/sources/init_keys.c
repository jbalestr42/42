/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 16:52:29 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 20:00:03 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_tracer.h"

static t_key	get_key_event(int keycode, t_key_event *event)
{
	t_key		key;

	key.keycode = keycode;
	key.is_press = 0;
	key.event = event;
	return (key);
}

void			init_events(t_env *e)
{
	e->key_events[0] = get_key_event(ESC, &key_event_esc);
	e->key_events[1] = get_key_event(KEY_S, &key_event_save);
	e->key_events[2] = get_key_event(KEY_R, &key_event_run_video);
	e->key_events[3] = get_key_event(KEY_1, &key_event_b_and_w);
	e->key_events[4] = get_key_event(KEY_2, &key_event_sepia);
	e->key_events[5] = get_key_event(KEY_3, &key_event_negative);
	e->key_events[6] = get_key_event(KEY_4, &key_event_none);
}
