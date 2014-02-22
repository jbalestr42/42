/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:10:28 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/02 20:29:01 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdlib.h>

int		key_hook(int keycode, t_env *e)
{
	(void)keycode;
	(void)e;
	return (0);
}

int		expose_hook(t_env *e)
{
	(void)e;
	return (0);
}

int		mouse_hook(int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	(void)e;
	return (0);
}

int		loop_hook(t_env *e)
{
	expose_hook(e);
	return (0);
}
