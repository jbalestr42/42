/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:36:46 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 18:38:00 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		update_mouse(t_env *env, float frametime)
{
	int			x;
	int			y;

	if (env->last_mouse_x != env->mouse_x || env->last_mouse_y != env->mouse_y)
	{
		x = env->last_mouse_x - env->mouse_x;
		y = env->last_mouse_y - env->mouse_y;
		if (x < 0)
			x = 1;
		else if (x > 0)
			x = -1;
		if (y < 0)
			y = 1;
		else if (y > 0)
			y = -1;
		env->camera.rotation[0] += x * frametime;
		env->camera.rotation[1] += y * frametime;
		env->last_mouse_x = env->mouse_x;
		env->last_mouse_y = env->mouse_y;
	}
}

void			update_camera_rotation(t_env *env, float frametime)
{
	t_matrix	r;

	identity(&r);
	update_mouse(env, frametime);
	rotate_about_x(&r, env->camera.rotation[1]);
	rotate_about_y(&r, env->camera.rotation[0]);
	init_vector(&env->camera.forward, 0.f, 0.f, 1.f);
	env->camera.forward = multiply_matrix_vector(&r, &env->camera.forward);
	normalize(&env->camera.forward);
	init_vector(&env->camera.up, 0.f, -1.f, 0.f);
	cross_product(&env->camera.right, &env->camera.up, &env->camera.forward);
	normalize(&env->camera.right);
	cross_product(&env->camera.up, &env->camera.right, &env->camera.forward);
	normalize(&env->camera.up);
	create_view_matrix(&env->view, &env->camera.up, &env->camera.right,
			&env->camera.forward);
}

void			update_camera_translation(t_env *env, float frametime)
{
	t_vector	position;

	init_vector(&position, 0.f, 0.f, 0.f);
	if (env->keys[KEY_FORWARD].is_active)
		add_vector(&position, &position, &env->camera.forward, 10.f
				* frametime);
	if (env->keys[KEY_BACKWARD].is_active)
		add_vector(&position, &position, &env->camera.forward, -10.f
				* frametime);
	if (env->keys[KEY_LEFT].is_active)
		add_vector(&position, &position, &env->camera.right, 10.f * frametime);
	if (env->keys[KEY_RIGHT].is_active)
		add_vector(&position, &position, &env->camera.right, -10.f * frametime);
	if (env->keys[KEY_UP].is_active)
		add_vector(&position, &position, &env->camera.up, -10.f * frametime);
	if (env->keys[KEY_DOWN].is_active)
		add_vector(&position, &position, &env->camera.up, 10.f * frametime);
	translate_matrix(&env->camera.translation, &position);
	env->view = multiply_matrices(&env->camera.translation, &env->view);
}

void			create_view_matrix(t_matrix *view, t_vector *up,
		t_vector *right, t_vector *forward)
{
	view->m[0] = right->v[0];
	view->m[4] = right->v[1];
	view->m[8] = right->v[2];
	view->m[1] = up->v[0];
	view->m[5] = up->v[1];
	view->m[9] = up->v[2];
	view->m[2] = forward->v[0];
	view->m[6] = forward->v[1];
	view->m[10] = forward->v[2];
	view->m[3] = 0.f;
	view->m[7] = 0.f;
	view->m[11] = 0.f;
	view->m[12] = 0.f;
	view->m[13] = 0.f;
	view->m[14] = 0.f;
	view->m[15] = 1.f;
}
