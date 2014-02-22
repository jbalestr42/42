/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:57:21 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 22:19:35 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
	e->key_events[1] = get_key_event(LEFT,  &key_event_left);
	e->key_events[2] = get_key_event(RIGHT,  &key_event_right);
	e->key_events[3] = get_key_event(PLUS,  &key_event_plus);
	e->key_events[4] = get_key_event(MOINS,  &key_event_moins);
	e->key_events[5] = get_key_event(KEY_W,  &key_event_key_w);
	e->key_events[6] = get_key_event(KEY_S,  &key_event_key_s);
	e->key_events[7] = get_key_event(KEY_A,  &key_event_key_a);
	e->key_events[8] = get_key_event(KEY_D,  &key_event_key_d);
	e->key_events[9] = get_key_event(KEY_1,  &key_event_key_1);
	e->key_events[10] = get_key_event(KEY_2,  &key_event_key_2);
	e->key_events[11] = get_key_event(KEY_3,  &key_event_key_3);
	e->key_events[12] = get_key_event(KEY_4,  &key_event_key_4);
}
