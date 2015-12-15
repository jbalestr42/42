#include "parsing.h"

void				setup_mesh_vertex(t_obj_data *obj_data, t_vertex_list *vertex_list)
{
	float			col[] = { 0.2f, 0.4f, 0.6f, 0.8f, 1.f };
	int				i;
	t_vertex_list	*tmp;

	i = obj_data->vertex_count - 1;
	obj_data->obj_vertices = (t_vertex*)malloc(sizeof(t_vertex) * obj_data->vertex_count);
	while (i >= 0)
	{
		obj_data->obj_vertices[i] = vertex_list->vertex;
		obj_data->obj_vertices[i].position[3] = 1.0f;
		obj_data->obj_vertices[i].color[0] = col[i % 5];
		obj_data->obj_vertices[i].color[1] = col[i % 5];
		obj_data->obj_vertices[i].color[2] = col[i % 5];
		obj_data->obj_vertices[i].color[3] = 1.0f;
		i--;
		tmp = vertex_list;
		vertex_list = vertex_list->next;
		free(tmp);
	}
}

void				setup_mesh_uv(t_obj_data *obj_data, t_uv_list *uv_list)
{
	int				i;
	t_uv_list		*tmp;

	i = obj_data->uv_count - 1;
	obj_data->obj_uvs = (t_uv*)malloc(sizeof(t_uv) * obj_data->uv_count);
	while (i >= 0)
	{
		obj_data->obj_uvs[i] = uv_list->uv;
		i--;
		tmp = uv_list;
		uv_list = uv_list->next;
		free(tmp);
	}
}

void				setup_mesh_faces(t_obj_data *obj_data, t_face_list *face_list)
{
	int				i;
	int				j;
	t_face_list		*tmp;
	int				*ids;
	int				count;

	i = 0;
	count = 0;
	obj_data->indice_count = obj_data->face_count * 3;
	obj_data->indices = (int*)malloc(sizeof(int) * obj_data->indice_count);
	obj_data->vertices = (t_vertex*)malloc(sizeof(t_vertex) * obj_data->indice_count);
	int uv_count = obj_data->uv_count > 0 ? obj_data->uv_count : 1;
	ids = (int*)malloc(sizeof(int) * obj_data->vertex_count * uv_count);
	while (i < obj_data->vertex_count * uv_count)
		ids[i++] = -1;
	i = 0;
	while (i < obj_data->face_count)
	{
		j = 0;
		while (j < 3)
		{
			int index = (face_list->face.indice_vertex[j] - 1) * uv_count + face_list->face.indice_texture[j] - 1;
			if (ids[index] == -1)
			{
				obj_data->vertices[count] = obj_data->obj_vertices[face_list->face.indice_vertex[j] - 1];
				obj_data->vertices[count].uv[0] = obj_data->obj_uvs[face_list->face.indice_texture[j] - 1].position[0];
				obj_data->vertices[count].uv[1] = obj_data->obj_uvs[face_list->face.indice_texture[j] - 1].position[1];
				ids[index] = count++;
			}
			obj_data->indices[i * 3 + j] = ids[index];
			j++;
		}
		i++;
		tmp = face_list;
		face_list = face_list->next;
		free(tmp);
	}
	obj_data->vertex_count = count;
	free(ids);
	printf("%d %d\n", obj_data->indice_count, count);
}

void				setup_mesh_origin(t_obj_data *obj_data)
{
	float			min[3];
	float			max[3];
	int				i;

	i = 0;
	while (i < 3)
	{
		min[i] = 99999999.f;
		max[i] = -99999999.f;
		i++;
	}
	i = 0;
	while (i < obj_data->vertex_count)
	{
		if (obj_data->obj_vertices[i].position[0] < min[0])
			min[0] = obj_data->obj_vertices[i].position[0];
		if (obj_data->obj_vertices[i].position[1] < min[1])
			min[1] = obj_data->obj_vertices[i].position[1];
		if (obj_data->obj_vertices[i].position[2] < min[2])
			min[2] = obj_data->obj_vertices[i].position[2];
		if (obj_data->obj_vertices[i].position[0] > max[0])
			max[0] = obj_data->obj_vertices[i].position[0];
		if (obj_data->obj_vertices[i].position[1] > max[1])
			max[1] = obj_data->obj_vertices[i].position[1];
		if (obj_data->obj_vertices[i].position[2] > max[2])
			max[2] = obj_data->obj_vertices[i].position[2];
		i++;
	}
	obj_data->origin.v[0] = (-min[0] - max[0]) / 2.f;
	obj_data->origin.v[1] = (-min[1] - max[1]) / 2.f;
	obj_data->origin.v[2] = (-min[2] - max[2]) / 2.f;
}
