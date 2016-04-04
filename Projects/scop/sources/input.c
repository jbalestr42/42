/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:00:37 by jbalestr          #+#    #+#             */
/*   Updated: 2016/03/10 15:00:50 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		keyboard_input_press(GLFWwindow *window, int key, int scancode,
		int action, int mods)
{
	t_env	*env;
	int		i;

	(void)scancode;
	(void)mods;
	env = glfwGetWindowUserPointer(window);
	i = 0;
	while (i < KEY_COUNT)
	{
		if (env->keys[i].code == key)
		{
			if (action == GLFW_PRESS)
				env->keys[i].is_active = 1;
			else if (action == GLFW_RELEASE)
				env->keys[i].is_active = 0;
		}
		i++;
	}
}

void		mouse_move_input(GLFWwindow *window, double x, double y)
{
	t_env	*env;

	env = glfwGetWindowUserPointer(window);
	env->mouse_x = x;
	env->mouse_y = y;
}
