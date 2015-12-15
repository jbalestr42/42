#include "scop.h"

void	resize_function(int width, int height)
{
	env.wnd_width = width;
	env.wnd_height = height;
	glViewport(0, 0, env.wnd_width, env.wnd_height);
	env.projection = create_projection_matrix(env.camera.fov, (float)env.wnd_width / env.wnd_height, env.camera.near_plane, env.camera.far_plane);
	glUseProgram(env.shader->program);
	glUniformMatrix4fv(env.shader->uniforms[2], 1, GL_FALSE, env.projection.m);
	glUseProgram(0);
}

void	render_function(void)
{
	++env.frame_count;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	draw();
	glutSwapBuffers();
}

void	timer_function(int value)
{
	if (0 != value)
	{
		char tmp[512 + strlen(WINDOW_TITLE_PREFIX)];
		sprintf(tmp, "%s: %d Frames Per Second @ %d x %d", WINDOW_TITLE_PREFIX, env.frame_count * 4, env.wnd_width, env.wnd_height);
		glutSetWindowTitle(tmp);
	}
	env.frame_count = 0;
	glutTimerFunc(250, timer_function, 1);
}
