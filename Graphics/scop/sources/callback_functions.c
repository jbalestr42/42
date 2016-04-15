/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:12:47 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 18:43:46 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		resize_function(GLFWwindow *window, int width, int height)
{
	t_env	*env;

	env = glfwGetWindowUserPointer(window);
	env->wnd_width = width;
	env->wnd_height = height;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	env->projection = create_projection_matrix(env->camera.fov,
			(float)env->wnd_width / env->wnd_height,
			env->camera.near_plane, env->camera.far_plane);
	glUseProgram(env->shader->program);
	glUniformMatrix4fv(env->shader->uniforms[2], 1, GL_FALSE,
			env->projection.m);
	glUseProgram(0);
}

void		error_callback(int error, char const *description)
{
	ft_putstr("ERROR [");
	ft_putnbr(error);
	ft_putstr("] : ");
	ft_putendl(description);
}

void		exit_on_glerror(const char *error_message)
{
	GLenum	error;

	error = glGetError();
	if (error != GL_NO_ERROR)
	{
		ft_putstr(error_message);
		ft_putstr(": [code=");
		ft_putnbr(error);
		ft_putendl("]");
		exit(EXIT_FAILURE);
	}
}
