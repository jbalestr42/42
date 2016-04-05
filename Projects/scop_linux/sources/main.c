#include "scop.h"

static int	parse_args(int argc, char **argv)
{
	if (argc >= 2)
	{
		init_env(&env);
		while (1)
			;
		init_openGL(argc, argv);
		env.mesh = create_mesh(argv[1]);
		if (!env.mesh)
			return (0);
		if (argc >= 3)
			env.texture = create_texture(argv[2]);
		env.shader = create_shader();
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (!parse_args(argc, argv))
		return (1);
	glutMainLoop();
	return (0);
}

void		clear(void)
{
	destroy_shader(env.shader);
	destroy_mesh(env.mesh);
	destroy_texture(env.texture);
}

void		draw(void)
{

	glUseProgram(env.shader->program);

	if (env.texture)
	{
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, env.texture->texture);
		glUniform1i(env.shader->uniforms[3], /*GL_TEXTURE*/0);
	}

	exit_on_GLerror("ERROR: Could not use the shader program");
	glUniformMatrix4fv(env.shader->uniforms[0], 1, GL_FALSE, env.mesh->transform.m);
	glUniformMatrix4fv(env.shader->uniforms[1], 1, GL_FALSE, env.view.m);
	glUniformMatrix4fv(env.shader->uniforms[2], 1, GL_FALSE, env.projection.m);
	glUniform1fv(env.shader->uniforms[4], 1, &env.mesh->transparency);
	exit_on_GLerror("ERROR: Could not set the shader uniforms");

	draw_mesh(env.mesh);

	glUseProgram(0);
}
