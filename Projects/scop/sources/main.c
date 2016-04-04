/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:12:18 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 15:17:36 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int	parse_args(t_env *env, int argc, char **argv)
{
	if (argc >= 2)
	{
		init_env(env);
		init_opengl(env);
		env->mesh = create_mesh(argv[1]);
		if (!env->mesh)
			return (0);
		if (argc >= 3)
			env->texture = create_texture(argv[2]);
		env->shader = create_shader();
		resize_function(env->window, env->wnd_width, env->wnd_height);
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_env	env;
	clock_t	last_time;
	clock_t	current_time;
	float	frametime;

	last_time = 0.f;
	if (!parse_args(&env, argc, argv))
		return (1);
	glfwSetTime(0.f);
	while (!glfwWindowShouldClose(env.window))
	{
		if (env.keys[KEY_ESC].is_active)
			glfwSetWindowShouldClose(env.window, 1);
		current_time = clock();
		frametime = (float)(current_time - last_time) / CLOCKS_PER_SEC * 100.f;
		last_time = current_time;
		update_mesh(&env, env.mesh, frametime);
		update_camera_rotation(&env, frametime);
		update_camera_translation(&env, frametime);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		draw(&env);
		glfwPollEvents();
	}
	clear(&env);
	return (0);
}

void		clear(t_env *env)
{
	destroy_shader(env->shader);
	destroy_mesh(env->mesh);
	destroy_texture(env->texture);
	glfwDestroyWindow(env->window);
	glfwTerminate();
}

void		draw(t_env *env)
{
	glUseProgram(env->shader->program);
	if (env->texture)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, env->texture->texture);
		glUniform1i(env->shader->uniforms[3], 0);
	}
	exit_on_glerror("ERROR: Could not use the shader program");
	glUniformMatrix4fv(env->shader->uniforms[0], 1, GL_FALSE,
			env->mesh->transform.m);
	glUniformMatrix4fv(env->shader->uniforms[1], 1, GL_FALSE, env->view.m);
	glUniformMatrix4fv(env->shader->uniforms[2], 1, GL_FALSE,
			env->projection.m);
	glUniform1fv(env->shader->uniforms[4], 1, &env->mesh->transparency);
	exit_on_glerror("ERROR: Could not set the shader uniforms");
	draw_mesh(env->mesh);
	glUseProgram(0);
	glfwSwapBuffers(env->window);
}
