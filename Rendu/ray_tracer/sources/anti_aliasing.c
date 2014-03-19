#include "ray_tracer.h"

static void		compute_pix(t_env *e, t_color *col, double dx, double dy)
{
	t_color		tmp;

	compute_ray(e, e->aa.ray, dx, dy);
	if (intersect_mesh(e, e->aa.ray, e->aa.mesh, e->aa.inter))
	{
		tmp = compute_color(e, e->aa.ray, *e->aa.mesh, 0, 1.0, e->aa.inter);
		col->r += tmp.r * 0.90;
		col->g += tmp.g * 0.90;
		col->b += tmp.b * 0.90;
	}
}

t_color			compute_aa(t_env *e, t_ray *ray, t_mesh **mesh, t_vertex *inter)
{
	t_color		col;
	double		dx;
	double		dy;

	e->aa.ray = ray;
	e->aa.mesh = mesh;
	e->aa.inter = inter;
	dx = e->aa.dx;
	dy = e->aa.dy;
	col = compute_color(e, ray, *mesh, 0, 1.0, inter);
	compute_pix(e, &col, e->aa.x + dx, e->aa.y);
	compute_pix(e, &col, e->aa.x + 2 * dx, e->aa.y);
	compute_pix(e, &col, e->aa.x, e->aa.y + dy);
	compute_pix(e, &col, e->aa.x, e->aa.y + 2 * dy);
	compute_pix(e, &col, e->aa.x - dx, e->aa.y);
	compute_pix(e, &col, e->aa.x - 2 * dx, e->aa.y);
	compute_pix(e, &col, e->aa.x, e->aa.y - dy);
	compute_pix(e, &col, e->aa.x, e->aa.y - 2 * dy);
	compute_pix(e, &col, e->aa.x + dx, e->aa.y + dy);
	compute_pix(e, &col, e->aa.x - dx, e->aa.y - dy);
	compute_pix(e, &col, e->aa.x + dx, e->aa.y - dy);
	compute_pix(e, &col, e->aa.x - dx, e->aa.y + dy);
	col.r /= 13;
	col.g /= 13;
	col.b /= 13;
	return (col);
}
