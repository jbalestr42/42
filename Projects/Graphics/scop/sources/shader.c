/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:12:23 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/11 10:24:44 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_shader		*create_shader(void)
{
	t_shader	*shader;

	shader = (t_shader*)malloc(sizeof(t_shader));
	if (!shader)
		return (NULL);
	shader->program = glCreateProgram();
	exit_on_glerror("ERROR: Could not create the shader program");
	shader->shaders[0] = load_shader("shaders/default.frag",
			GL_FRAGMENT_SHADER);
	shader->shaders[1] = load_shader("shaders/default.vert",
			GL_VERTEX_SHADER);
	glAttachShader(shader->program, shader->shaders[0]);
	glAttachShader(shader->program, shader->shaders[1]);
	glLinkProgram(shader->program);
	exit_on_glerror("ERROR: Could not link the shader program");
	shader->uniforms[0] = glGetUniformLocation(shader->program, "ModelMatrix");
	shader->uniforms[1] = glGetUniformLocation(shader->program, "ViewMatrix");
	shader->uniforms[2] = glGetUniformLocation(shader->program,
			"ProjectionMatrix");
	shader->uniforms[3] = glGetUniformLocation(shader->program, "tex");
	shader->uniforms[4] = glGetUniformLocation(shader->program, "transparency");
	exit_on_glerror("ERROR: Could not get shader uniform locations");
	return (shader);
}

void			destroy_shader(t_shader *shader)
{
	if (shader)
	{
		glDetachShader(shader->program, shader->shaders[0]);
		glDetachShader(shader->program, shader->shaders[1]);
		glDeleteShader(shader->shaders[0]);
		glDeleteShader(shader->shaders[1]);
		glDeleteProgram(shader->program);
		free(shader);
		exit_on_glerror("ERROR: Could not destroy the shaders");
	}
}

static char		*read_shader(const char *filename)
{
	FILE		*file;
	long		size;
	char		*glsl_source;

	size = -1;
	file = fopen(filename, "rb");
	if (file && fseek(file, 0, SEEK_END) == 0 && (size = ftell(file)) != -1)
	{
		rewind(file);
		if ((glsl_source = (char*)malloc(size + 1)) != NULL)
		{
			if (size == (long)fread(glsl_source, sizeof(char), size, file))
			{
				glsl_source[size] = '\0';
				return (glsl_source);
			}
			ft_putendl("ERROR: Could not read file.");
		}
		ft_putendl("ERROR: Could not allocate enough bytes.");
		fclose(file);
	}
	if (file)
		fclose(file);
	ft_putendl("ERROR: Could not open file.");
	return (NULL);
}

GLuint			load_shader(const char *filename, GLenum shader_type)
{
	GLuint		shader_id;
	char		*glsl_source;

	shader_id = 0;
	glsl_source = read_shader(filename);
	shader_id = glCreateShader(shader_type);
	if (glsl_source && shader_id != 0)
	{
		glShaderSource(shader_id, 1, (const GLchar **)&glsl_source, NULL);
		glCompileShader(shader_id);
		free(glsl_source);
		exit_on_glerror("Could not compile a shader");
	}
	else
		ft_putendl("ERROR: Could not create a shader.");
	return (shader_id);
}
