/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:46:25 by jbalestr          #+#    #+#             */
/*   Updated: 2016/04/11 10:37:12 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		generate_buffer(t_mesh *mesh)
{
	glGenVertexArrays(1, &mesh->vertex_array_object);
	exit_on_glerror("ERROR: Could not generate the VAO");
	glBindVertexArray(mesh->vertex_array_object);
	exit_on_glerror("ERROR: Could not bind the VAO");
	glGenBuffers(2, mesh->vertex_buffer_object);
	exit_on_glerror("ERROR: Could not generate the buffer objects");
}

t_mesh			*create_mesh(char const *filename)
{
	t_obj_data	obj_data;
	t_mesh		*mesh;

	if (!(mesh = init_mesh(&obj_data, filename)))
		return (NULL);
	generate_buffer(mesh);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->vertex_buffer_object[POSITION_VB]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(t_vertex) * obj_data.vertex_count,
			obj_data.vertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(t_vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(t_vertex),
			(GLvoid*)(sizeof(obj_data.obj_vertices[0].position)
				+ sizeof(obj_data.obj_vertices[0].uv)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(t_vertex),
			(GLvoid*)(sizeof(obj_data.obj_vertices[0].position)));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->vertex_buffer_object[INDEX_VB]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLushort)
			* obj_data.indice_count, obj_data.indices, GL_STATIC_DRAW);
	exit_on_glerror("ERROR: Could not bind the IBO to the VAO");
	glBindVertexArray(0);
	destroy_obj_data(&obj_data);
	return (mesh);
}

void			destroy_mesh(t_mesh *mesh)
{
	if (mesh)
	{
		glDeleteBuffers(3, mesh->vertex_buffer_object);
		glDeleteVertexArrays(1, &mesh->vertex_array_object);
		exit_on_glerror("ERROR: Could not destroy the buffer objects");
		free(mesh);
	}
}

void			draw_mesh(t_mesh *mesh)
{
	glBindVertexArray(mesh->vertex_array_object);
	exit_on_glerror("ERROR: Could not bind the VAO for drawing purposes");
	glDrawElements(GL_TRIANGLES, mesh->indice_count,
			GL_UNSIGNED_SHORT, (GLvoid*)0);
	exit_on_glerror("ERROR: Could not draw the cube");
	glBindVertexArray(0);
}

void			update_mesh(t_env *env, t_mesh *mesh, float frametime)
{
	mesh->rotation += 45.0f * (frametime);
	identity(&mesh->transform);
	translate_matrix(&mesh->transform, &env->mesh->origin);
	rotate_about_y(&mesh->transform, degrees_to_radians(mesh->rotation));
	if (env->keys[KEY_P].is_active)
		env->mesh->scale += 1.f * frametime;
	if (env->keys[KEY_M].is_active)
	{
		env->mesh->scale -= 1.f * frametime;
		if (env->mesh->scale < 0.f)
			env->mesh->scale = 0.f;
	}
	scale_matrix(&mesh->transform, mesh->scale, mesh->scale, mesh->scale);
	if (env->keys[KEY_L].is_active)
	{
		if (mesh->transparency >= 1.f)
			mesh->transition = 1;
		else if (mesh->transparency <= 0.f)
			mesh->transition = 0;
	}
	if (mesh->transition && mesh->transparency > 0.f)
		mesh->transparency -= frametime;
	else if (!mesh->transition && mesh->transparency < 1.f)
		mesh->transparency += frametime;
}
