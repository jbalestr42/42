/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/12 15:42:52 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/19 18:01:06 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "ray_tracer.h"
#include "parser.h"

void			init_scene(t_env *e, char *path)
{
	/*(void)path;
	e->nb_mesh = 7;
	e->meshes = (t_mesh *)malloc(sizeof(t_mesh) * e->nb_mesh);
	e->meshes[0].type = T_SPHERE;
	e->meshes[0].prim.sphere.radius = 2.0;
	e->meshes[0].color.r = 0.9;
	e->meshes[0].color.g = 0.8;
	e->meshes[0].color.b = 0.8;
	e->meshes[0].diff = 0.8;
	e->meshes[0].spec = 0.8;
	e->meshes[0].refl = 0.0;
	e->meshes[0].refr = 0.0;
	e->meshes[0].trans = malloc_matrix(4, 4);
	e->meshes[0].scale = malloc_matrix(4, 4);
	e->meshes[0].rot_x = malloc_matrix(4, 4);
	e->meshes[0].rot_y = malloc_matrix(4, 4);
	e->meshes[0].rot_z = malloc_matrix(4, 4);
	inv_scale_matrix(&e->meshes[0].scale, 1.0, 1.0, 1.0);
	inv_rot_matrix_x(&e->meshes[0].rot_x, 0.0);
	inv_rot_matrix_y(&e->meshes[0].rot_y, 0.0);
	inv_rot_matrix_z(&e->meshes[0].rot_z, 0.0);
	inv_trans_matrix(&e->meshes[0].trans, 8.0, -12.0, -2.0);
	compute_matrix(&e->meshes[0]);
	e->meshes[1].type = T_SPHERE;
	e->meshes[1].prim.sphere.radius = 5.0;
	e->meshes[1].color.r = 0.1;
	e->meshes[1].color.g = 0.0;
	e->meshes[1].color.b = 0.8;
	e->meshes[1].diff = 0.8;
	e->meshes[1].spec = 1.0;
	e->meshes[1].refl = 0.0;
	e->meshes[1].refr = 0.0;
	e->meshes[1].trans = malloc_matrix(4, 4);
	e->meshes[1].scale = malloc_matrix(4, 4);
	e->meshes[1].rot_x = malloc_matrix(4, 4);
	e->meshes[1].rot_y = malloc_matrix(4, 4);
	e->meshes[1].rot_z = malloc_matrix(4, 4);
	inv_scale_matrix(&e->meshes[1].scale, 1.0, 1.0, 1.0);
	inv_rot_matrix_x(&e->meshes[1].rot_x, 0.0);
	inv_rot_matrix_y(&e->meshes[1].rot_y, 0.0);
	inv_rot_matrix_z(&e->meshes[1].rot_z, 0.0);
	inv_trans_matrix(&e->meshes[1].trans, -3.0, 0.0, 0.0);
	compute_matrix(&e->meshes[1]);
	e->meshes[2].type = T_CONE;
	e->meshes[2].prim.cone.coeff = 0.1;
	e->meshes[2].color.r = 0.8;
	e->meshes[2].color.g = 0.1;
	e->meshes[2].color.b = 0.5;
	e->meshes[2].diff = 0.8;
	e->meshes[2].spec = 1.0;
	e->meshes[2].refl = 0.0;
	e->meshes[2].refr = 0.0;
	e->meshes[2].trans = malloc_matrix(4, 4);
	e->meshes[2].scale = malloc_matrix(4, 4);
	e->meshes[2].rot_x = malloc_matrix(4, 4);
	e->meshes[2].rot_y = malloc_matrix(4, 4);
	e->meshes[2].rot_z = malloc_matrix(4, 4);
	inv_scale_matrix(&e->meshes[2].scale, 0.2, 0.2, 0.2);
	inv_rot_matrix_x(&e->meshes[2].rot_x, 0.0);
	inv_rot_matrix_y(&e->meshes[2].rot_y, 0.0);
	inv_rot_matrix_z(&e->meshes[2].rot_z, 1.0);
	inv_trans_matrix(&e->meshes[2].trans, 19.0, 9.0, 0.0);
	compute_matrix(&e->meshes[2]);
	e->meshes[3].type = T_PLAN;
	e->meshes[3].prim.plan.normal = init_vec(1.0, 1.0, 0.0);
	e->meshes[3].color.r = 0.1;
	e->meshes[3].color.g = 0.8;
	e->meshes[3].color.b = 0.5;
	e->meshes[3].diff = 0.8;
	e->meshes[3].spec = 1.0;
	e->meshes[3].refl = 0.0;
	e->meshes[3].refr = 0.0;
	e->meshes[3].trans = malloc_matrix(4, 4);
	e->meshes[3].scale = malloc_matrix(4, 4);
	e->meshes[3].rot_x = malloc_matrix(4, 4);
	e->meshes[3].rot_y = malloc_matrix(4, 4);
	e->meshes[3].rot_z = malloc_matrix(4, 4);
	inv_scale_matrix(&e->meshes[3].scale, 1.0, 1.0, 1.0);
	inv_rot_matrix_x(&e->meshes[3].rot_x, 0.0);
	inv_rot_matrix_y(&e->meshes[3].rot_y, 0.0);
	inv_rot_matrix_z(&e->meshes[3].rot_z, 0.0);
	inv_trans_matrix(&e->meshes[3].trans, -25.0, 0.0, 0.0);
	compute_matrix(&e->meshes[3]);
	e->meshes[4].type = T_CYLINDER;
	e->meshes[4].prim.cylinder.radius = 5;
	e->meshes[4].color.r = 0.8;
	e->meshes[4].color.g = 0.9;
	e->meshes[4].color.b = 0.2;
	e->meshes[4].diff = 1.0;
	e->meshes[4].spec = 1.0;
	e->meshes[4].refl = 0.0;
	e->meshes[4].refr = 0.0;
	e->meshes[4].trans = malloc_matrix(4, 4);
	e->meshes[4].scale = malloc_matrix(4, 4);
	e->meshes[4].rot_x = malloc_matrix(4, 4);
	e->meshes[4].rot_y = malloc_matrix(4, 4);
	e->meshes[4].rot_z = malloc_matrix(4, 4);
	inv_scale_matrix(&e->meshes[4].scale, 0.2, 0.2, 0.2);
	inv_rot_matrix_x(&e->meshes[4].rot_x, 1.0);
	inv_rot_matrix_y(&e->meshes[4].rot_y, 0.0);
	inv_rot_matrix_z(&e->meshes[4].rot_z, 0.0);
	inv_trans_matrix(&e->meshes[4].trans, 19.0, 9.0, 0.0);
	compute_matrix(&e->meshes[4]);
	e->meshes[5].type = T_PARABOLE;
	e->meshes[5].prim.parabole.coeff = 0.2;
	e->meshes[5].color.r = 0.8;
	e->meshes[5].color.g = 0.0;
	e->meshes[5].color.b = 0.2;
	e->meshes[5].diff = 1.0;
	e->meshes[5].spec = 1.0;
	e->meshes[5].refl = 0.0;
	e->meshes[5].refr = 0.0;
	e->meshes[5].trans = malloc_matrix(4, 4);
	e->meshes[5].scale = malloc_matrix(4, 4);
	e->meshes[5].rot_x = malloc_matrix(4, 4);
	e->meshes[5].rot_y = malloc_matrix(4, 4);
	e->meshes[5].rot_z = malloc_matrix(4, 4);
	inv_scale_matrix(&e->meshes[5].scale, 0.2, 0.2, 0.2);
	inv_rot_matrix_x(&e->meshes[5].rot_x, -1.0);
	inv_rot_matrix_y(&e->meshes[5].rot_y, 0.0);
	inv_rot_matrix_z(&e->meshes[5].rot_z, 0.0);
	inv_trans_matrix(&e->meshes[5].trans, 9.0, 9.0, 0.0);
	compute_matrix(&e->meshes[5]);
	e->meshes[6].type = T_HYPERBOLE;
	e->meshes[6].prim.hyperbole.coeff = 0.15;
	e->meshes[6].prim.hyperbole.open = 4;
	e->meshes[6].color.r = 0.6;
	e->meshes[6].color.g = 0.2;
	e->meshes[6].color.b = 0.9;
	e->meshes[6].diff = 0.8;
	e->meshes[6].spec = 1.0;
	e->meshes[6].refl = 0.0;
	e->meshes[6].refr = 0.0;
	e->meshes[6].trans = malloc_matrix(4, 4);
	e->meshes[6].scale = malloc_matrix(4, 4);
	e->meshes[6].rot_x = malloc_matrix(4, 4);
	e->meshes[6].rot_y = malloc_matrix(4, 4);
	e->meshes[6].rot_z = malloc_matrix(4, 4);
	inv_scale_matrix(&e->meshes[6].scale, 0.2, 0.2, 0.2);
	inv_rot_matrix_x(&e->meshes[6].rot_x, 2.0);
	inv_rot_matrix_y(&e->meshes[6].rot_y, 0.0);
	inv_rot_matrix_z(&e->meshes[6].rot_z, 0.4);
	inv_trans_matrix(&e->meshes[6].trans, 39.0, 19.0, 0.0);
	compute_matrix(&e->meshes[6]);

	e->cam.pos = init_vec(55.0, -15.0, -100.0);
	//e->cam.pos = init_vec(660.0, 20.0, 0.0);
	e->look_at_point = init_vec(0.0, 0.0, 0.0);
	e->ambient = 0.2;
	e->nb_light = 2;
	e->lights = (t_light *)malloc(sizeof(t_light) * e->nb_light);
	e->lights[0].color.r = 0.3;
	e->lights[0].color.g = 0.3;
	e->lights[0].color.b = 0.3;
	e->lights[0].pos = init_vec(500.0, 0.0, 0.0);
	e->lights[1].color.r = 0.3;
	e->lights[1].color.g = 0.3;
	e->lights[1].color.b = 0.3;
	e->lights[1].pos = init_vec(420, 80, -70);*/
	parse(e, path);
}
