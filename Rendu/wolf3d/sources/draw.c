/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 20:05:15 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 22:32:42 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <mlx.h>

static void		ft_draw_floor(t_env *e, int x, int start)
{
	int			i;
	int			j;

	j = start;
	while (j < HEIGHT)
	{
		i = j * e->screen.size_line + x * e->screen.bpp;
		if (i > 0 && i < e->screen.max_size)
		{
			e->screen.img[i] = 120;
			e->screen.img[i + 1] = 120;
			e->screen.img[i + 2] = 120;
		}
		j++;
	}
}

static void		ft_draw_sky(t_env *e, int x, int y)
{
	int			i;
	int			j;
	int			k;
	t_point		offset;
	t_img		*img;

	j = -1;
	img = &e->sky;
	offset.x = x * img->width / WIDTH;
	while (++j <= y)
	{
		i = j * e->screen.size_line + x * e->screen.bpp;
		if (i > 0 && i < e->screen.max_size)
		{
			offset.y = j * img->height / HEIGHT;
			k = offset.y * img->size_line + offset.x * img->bpp;
			if (k > 0 && k < img->max_size)
			{
				e->screen.img[i] = img->img[k];
				e->screen.img[i + 1] = img->img[k + 1];
				e->screen.img[i + 2] = img->img[k + 2];
			}
		}
	}
}

static void		ft_draw_texture(t_env *e, t_point *p, int l_c_m[3], double col)
{
	int			i;
	int			j;
	t_fpoint	offset;
	t_img		*img;

	img = e->current_wall;
	offset.x = ((int)col % SIZE) * img->width / SIZE;
	while (l_c_m[0]-- > 0)
	{
		i = (p->y + l_c_m[0]) * e->screen.size_line + p->x * e->screen.bpp;
		if (i > 0 && i < e->screen.max_size)
		{
			offset.y = (l_c_m[0] + l_c_m[1]) * img->frame_size / l_c_m[2];
			offset.y = offset.y + (int)img->current_frame * img->frame_size;
			j = offset.y * img->size_line + offset.x * img->bpp;
			if (j > 0 && j < img->max_size)
			{
				e->screen.img[i] = img->img[j];
				e->screen.img[i + 1] = img->img[j + 1];
				e->screen.img[i + 2] = img->img[j + 2];
			}
		}
	}
}

/*
** l_c_m = len correct max
*/
static void		ft_draw_line(t_env *e, t_point *p, int len, double collide)
{
	int			l_c_m[3];

	l_c_m[2] = len;
	l_c_m[1] = 0;
	if (len > HEIGHT)
	{
		l_c_m[1] = (len - HEIGHT) / 2;
		p->y = 0;
		len = HEIGHT;
	}
	l_c_m[0] = len;
	ft_draw_texture(e, p, l_c_m, collide);
	ft_draw_sky(e, p->x, p->y);
	ft_draw_floor(e, p->x, l_c_m[2] + p->y);
	ft_draw_hud(e, p->x);
	ft_draw_weapon(e, p->x);
}

void			ft_draw_view(t_env *e)
{
	t_point		p;
	double		collide;
	double		beta;
	int			i;
	int			len;

	i = -1;
	beta = e->pov.alpha + (e->fov / 2);
	beta -= beta > 360 ? 360 : 0;
	while (++i < WIDTH)
	{
		if ((len = column_height(e, beta, &collide)) > 0)
		{
			p.x = i;
			p.y = e->current_height - len / 2;
			ft_draw_line(e, &p, len, collide);
		}
		else
		{
			ft_draw_sky(e, i, e->current_height);
			ft_draw_floor(e, i, e->current_height);
		}
		beta -= e->step_angle;
		beta += beta < 0 ? 360 : 0;
	}
}
