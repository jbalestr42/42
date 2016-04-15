/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 01:47:38 By jbalestr          #+#    #+#             */
/*   Updated: 2013/12/18 14:53:45 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

void	ft_draw_line(t_env *e, t_point p1, t_point p2)
{
	t_point		d;
	t_point		s;
	int			err;
	int			e2;

	d.x = ABS(p2.x - p1.x);
	d.y = ABS(p2.y - p1.y);
	s.x = p1.x < p2.x ? 1 : -1;
	s.y = p1.y < p2.y ? 1 : -1;
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (42)
	{
		mlx_pixel_put(e->mlx, e->win, p1.x + e->cam.x, p1.y + e->cam.y, RED);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = err;
		if (e2 > -d.x && ((err -= d.y) || !err))
			p1.x += s.x;
		if (e2 < d.y)
		{
			err += d.x;
			p1.y += s.y;
		}
	}
}

void	ft_draw_rect(t_env *e, t_point *p1, t_point *p2)
{
	t_point		p3;
	t_point		p4;

	p3.x = p1->x;
	p3.y = p2->y;
	p4.x = p2->x;
	p4.y = p1->y;
	ft_draw_line(e, *p1, p3);
	ft_draw_line(e, p3, *p2);
	ft_draw_line(e, *p2, p4);
	ft_draw_line(e, p4, *p1);
}

void	ft_draw_map(t_env *e)
{
	t_point		pt1;
	t_point		pt2;
	int			i;
	int			j;

	i = 0;
	while (i < e->nb_line && !(j = 0))
	{
		while (j < e->size[i])
		{
			pt1 = ft_get_point(e, e->points[i][j], &ft_iso);
			if (j < e->size[i] - 1)
			{
				pt2 = ft_get_point(e, e->points[i][j + 1], &ft_iso);
				ft_draw_line(e, pt1, pt2);
			}
			if (i < (e->nb_line - 1) && j < e->size[i + 1])
			{
				pt2 = ft_get_point(e, e->points[i + 1][j], &ft_iso);
				ft_draw_line(e, pt1, pt2);
			}
			j++;
		}
		i++;
	}
}
