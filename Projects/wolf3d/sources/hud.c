/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 20:02:03 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/19 22:49:07 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	valid_color(t_img *m, int k)
{
	if (m->img[k] == (char)0xFE)
	{
		if (m->img[k + 1] == (char)0x0 && m->img[k + 2] == (char)0xFE)
			return (1);
	}
	return (0);
}

void		draw_pix(t_env *e, int k, t_img *m, int i)
{
	if (k > 0 && k < m->max_size)
	{
		if (valid_color(m, k))
			return ;
		e->screen.img[i] = m->img[k];
		e->screen.img[i + 1] = m->img[k + 1];
		e->screen.img[i + 2] = m->img[k + 2];
	}
}

void		ft_draw_hud(t_env *e, int x)
{
	int			i;
	int			j;
	int			k;
	double		off;
	t_img		*m;

	j = -1;
	m = &e->hud;
	if (x < (WIDTH / 2 - m->width / 2) || x > (WIDTH / 2 + m->width / 2 - 1))
		return ;
	while (++j < m->frame_size)
	{
		i = (j + HEIGHT - m->frame_size) * e->screen.size_line;
		i += x * e->screen.bpp;
		if (i > 0 && i < e->screen.max_size)
		{
			off = j + (int)m->current_frame * m->frame_size;
			k = off * m->size_line + (x - WIDTH / 2 + m->width / 2) * m->bpp;
			draw_pix(e, k, m, i);
		}
	}
}

void		ft_draw_weapon(t_env *e, int x)
{
	int			i;
	int			j;
	int			k;
	double		offset;
	t_img		*m;

	j = -1;
	m = &e->weapon;
	if (x < (WIDTH - m->width) || x > WIDTH)
		return ;
	while (++j < m->frame_size)
	{
		i = (j + HEIGHT - m->frame_size) * e->screen.size_line;
		i += x * e->screen.bpp;
		if (i > 0 && i < e->screen.max_size)
		{
			offset = j + (int)m->current_frame * m->frame_size;
			k = (offset + 1) * m->size_line + (x - WIDTH) * m->bpp;
			draw_pix(e, k, m, i);
		}
	}
}
