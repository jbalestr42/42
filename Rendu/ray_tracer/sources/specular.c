#include <math.h>
#include "ray_tracer.h"

static void		spec_col(t_color *c, t_color *objc, t_color *lic, double spec)
{
	(void)objc;
	c->r = spec * lic->r;
	c->g = spec * lic->g;
	c->b = spec * lic->b;
}

t_color			specular(t_env *e, t_light *light, t_mesh *mesh, t_ray *ray, t_ray *cam_ray)
{
	t_color		col;
	t_vector	normal;
	t_vector	r;
	double		d;
	double		spec;

	col.r = 0.0;
	col.g = 0.0;
	col.b = 0.0;
	normal = e->normals[mesh->type](mesh, &ray->pos);
	r = sub(ray->dir, prod_val(normal, 2.0 * dot(ray->dir, normal)));
	d = dot(cam_ray->dir, normalize(r));
	if (d > 0)
	{
		spec = pow(d, 30) * mesh->spec;
		spec_col(&col, &mesh->color, &light->color, spec);
	}
	return (col);
}
