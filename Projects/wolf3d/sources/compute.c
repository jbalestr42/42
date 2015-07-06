/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:57:21 by jbalestr          #+#    #+#             */
/*   Updated: 2014/01/24 11:29:42 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>
#include <stdlib.h>

static int		inter(t_env *e, int xx, int yy, t_img **img)
{
	int		wall;
	int		i;

	if (xx >= e->width_px && xx < 0 && yy < 0 && yy >= e->height_px)
		return (0);
	wall = e->map[yy / SIZE][xx / SIZE];
	i = 0;
	while (i < NB_WALL)
	{
		if (e->walls[i].type == wall)
		{
			*img = &e->walls[i];
			return (1);
		}
		i++;
	}
	*img = e->current_wall;
	return (0);
}

static int		search_hori(t_env *e, t_fpoint *p, double beta, t_img **img)
{
	t_fpoint	step;
	int			dir;

	dir = beta >= 0 && beta < 180 ? -1 : 0;
	p->y = (e->pov.pos.y / SIZE) * SIZE;
	p->y += beta >= 0 && beta < 180 ? 0 : SIZE;
	p->rgb = beta >= 0 && beta < 180 ? 270 : 1240;
	p->x = e->pov.pos.x + (e->pov.pos.y - p->y) / ft_tan(beta);
	step.y = beta >= 0 && beta < 180 ? -SIZE : SIZE;
	step.x = -step.y / ft_tan(beta);
	while (p->y >= 0 && p->y < e->height_px && p->x >= 0 && p->x < e->width_px)
	{
		if (inter(e, p->x, p->y + dir, img) == 1)
			return (1);
		p->y += step.y;
		p->x += step.x;
	}
	return (0);
}

static int		search_vert(t_env *e, t_fpoint *p, double beta, t_img **img)
{
	t_fpoint	step;
	int			dir;

	dir = beta >= 90 && beta < 270 ? -1 : 0;
	p->x = (e->pov.pos.x / SIZE) * SIZE;
	p->x += beta >= 90 && beta < 270 ? 0 : SIZE;
	p->rgb = beta >= 90 && beta < 270 ? 45000 : 2000;
	p->y = e->pov.pos.y + (e->pov.pos.x - p->x) * ft_tan(beta);
	step.x = beta >= 90 && beta < 270 ? -SIZE : SIZE;
	step.y = -step.x * ft_tan(beta);
	while (p->y >= 0 && p->y < e->height_px && p->x >= 0 && p->x < e->width_px)
	{
		if (inter(e, p->x + dir, p->y, img) == 1)
			return (1);
		p->x += step.x;
		p->y += step.y;
	}
	return (0);
}

static double	dist(t_env *e, t_fpoint *p, double beta)
{
	double		d;

	d = sqrt(ft_square(e->pov.pos.x - p->x) + ft_square(e->pov.pos.y - p->y));
	d *= ft_cos(ABS(e->pov.alpha - beta));
	return (d);
}

int				column_height(t_env *e, double beta, double *p)
{
	t_fpoint	dist_hv;
	t_fpoint	p_hori;
	t_fpoint	p_vert;
	t_img		*i_hori;
	t_img		*i_vert;

	dist_hv.x = dist_hv.y = DBL_MAX;
	i_hori = i_vert = e->current_wall;
	if (search_hori(e, &p_hori, beta, &i_hori))
		dist_hv.x = dist(e, &p_hori, beta);
	if (search_vert(e, &p_vert, beta, &i_vert))
		dist_hv.y = dist(e, &p_vert, beta);
	if (dist_hv.x < dist_hv.y)
	{
		*p = p_hori.x;
		e->current_wall = i_hori;
		return (e->dist_size / dist_hv.x);
	}
	else if (dist_hv.x > dist_hv.y)
	{
		*p = p_vert.y;
		e->current_wall = i_vert;
		return (e->dist_size / dist_hv.y);
	}
	return (-1);
}
