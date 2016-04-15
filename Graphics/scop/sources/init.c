/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 18:38:20 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 18:40:57 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		init_key(t_env *env)
{
	env->keys[KEY_ESC].code = 256;
	env->keys[KEY_ESC].is_active = 0;
	env->keys[KEY_FORWARD].code = 87;
	env->keys[KEY_FORWARD].is_active = 0;
	env->keys[KEY_BACKWARD].code = 83;
	env->keys[KEY_BACKWARD].is_active = 0;
	env->keys[KEY_LEFT].code = 65;
	env->keys[KEY_LEFT].is_active = 0;
	env->keys[KEY_RIGHT].code = 68;
	env->keys[KEY_RIGHT].is_active = 0;
	env->keys[KEY_UP].code = 'e';
	env->keys[KEY_UP].is_active = 0;
	env->keys[KEY_DOWN].code = 'a';
	env->keys[KEY_DOWN].is_active = 0;
	env->keys[KEY_P].code = 80;
	env->keys[KEY_P].is_active = 0;
	env->keys[KEY_M].code = 77;
	env->keys[KEY_M].is_active = 0;
	env->keys[KEY_L].code = 76;
	env->keys[KEY_L].is_active = 0;
}

void		init_env(t_env *env)
{
	env->frame_count = 0;
	env->wnd_width = 800;
	env->wnd_height = 600;
	env->wnd_handle = 0;
	identity(&env->projection);
	env->window = NULL;
	env->mesh = NULL;
	env->shader = NULL;
	env->texture = NULL;
	init_key(env);
	env->camera.fov = 60.f;
	env->camera.near_plane = 1.f;
	env->camera.far_plane = 100.f;
	env->camera.rotation[0] = 0.f;
	env->camera.rotation[1] = 0.f;
	identity(&env->camera.translation);
	env->camera.translation.m[14] = -6;
}

void		init_opengl(t_env *env)
{
	GLenum	result;

	init_window(env);
	glfwMakeContextCurrent(env->window);
	glewExperimental = 1;
	result = glewInit();
	glGetError();
	if (result)
	{
		ft_putstr("ERROR: ");
		ft_putendl((char const *)glewGetErrorString(result));
		exit(EXIT_FAILURE);
	}
	glfwSwapInterval(1);
	glfwGetFramebufferSize(env->window, &env->wnd_width, &env->wnd_height);
	ft_putstr("INFO: OpenGL Version: ");
	ft_putendl((const char *)glGetString(GL_VERSION));
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	exit_on_glerror("ERROR: Could not set OpenGL depth testing options");
	glFrontFace(GL_CCW);
	exit_on_glerror("ERROR: Could not set OpenGL culling options");
}

void		init_window(t_env *env)
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		exit(EXIT_FAILURE);
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_DEPTH_BITS, 16);
	glfwWindowHint(GLFW_RESIZABLE, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, 1);
	env->window = glfwCreateWindow(env->wnd_width, env->wnd_height,
			WINDOW_TITLE_PREFIX, NULL, NULL);
	if (!env->window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetFramebufferSizeCallback(env->window, resize_function);
	glfwSetKeyCallback(env->window, keyboard_input_press);
	glfwSetCursorPosCallback(env->window, mouse_move_input);
	glfwSetInputMode(env->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetWindowUserPointer(env->window, env);
}

t_mesh		*init_mesh(t_obj_data *obj_data, char const *filename)
{
	t_mesh	*mesh;

	if (!load_mesh(obj_data, filename))
		return (NULL);
	mesh = (t_mesh*)malloc(sizeof(t_mesh));
	if (!mesh)
		return (NULL);
	mesh->indice_count = obj_data->indice_count;
	mesh->origin = obj_data->origin;
	identity(&mesh->transform);
	mesh->rotation = 0.f;
	mesh->scale = 1.f;
	mesh->transparency = 0.f;
	mesh->transition = 1;
	return (mesh);
}
