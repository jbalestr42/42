/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebelle <mdebelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 05:17:51 by mdebelle          #+#    #+#             */
/*   Updated: 2014/03/27 05:17:53 by mdebelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "ray_tracer.h"

static void		foreach_button(t_screen *s, int x, t_img *img)
{
	int			y;
	int			t;
	int			tt;

	y = -1;
	while (++y < s->buttons[3].frame_size)
	{
		t = (s->buttons[3].state * s->buttons[3].frame_size + y)
				* s->buttons[3].img.size_line + (x * s->buttons[3].img.bpp);
		if (t > 0 && t < s->buttons[3].img.max_size)
		{
			tt = (s->buttons[3].y_pos + y) * img->size_line
						+ ((s->buttons[3].x_pos + x) * img->bpp);
			if (tt > 0 && tt < img->max_size)
			{
				img->img[tt] = s->buttons[3].img.img[t];
				img->img[tt + 1] = s->buttons[3].img.img[t + 1];
				img->img[tt + 2] = s->buttons[3].img.img[t + 2];
			}
		}
	}
}

void			refresh_load(t_env *e, double prog)
{
	t_screen	*s;
	int			x;
	double		xx;
	t_img		img;

	s = &e->screens[e->cur_screen];
	img = s->background;
	s->buttons[3].state = HOVER;
	x = -1;
	while (++x < s->buttons[3].img.width)
	{
		xx = x / (double)s->buttons[3].img.width;
		if (xx > prog)
			s->buttons[3].state = NONE;
		foreach_button(s, x, &img);
	}
	mlx_put_image_to_window(e->mlx, e->win, img.ptr, 0, 0);
}
