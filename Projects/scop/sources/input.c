#include "scop.h"

void		keyboard_input_press(unsigned char key, int x, int y)
{
	int		i;

	(void)x;
	(void)y;
	i = 0;
	while (i < KEY_COUNT)
	{
		if (env.keys[i].code == key)
			env.keys[i].is_active = 1;
		i++;
	}
}

void		keyboard_input_release(unsigned char key, int x, int y)
{
	int		i;

	(void)x;
	(void)y;
	i = 0;
	while (i < KEY_COUNT)
	{
		if (env.keys[i].code == key)
			env.keys[i].is_active = 0;
		i++;
	}
}

void		mouse_move_input(int x, int y)
{
	env.mouse_x = x;
	env.mouse_y = y;
}

void		idle_function(void)
{
	clock_t		current_time;
	float		frametime;

	current_time = clock();
	frametime = (float)(current_time - env.last_time) / CLOCKS_PER_SEC;
	env.last_time = current_time;
	update_mesh(env.mesh, frametime);
	update_camera_rotation(frametime);
	update_camera_translation(frametime);
	glutPostRedisplay();
}
