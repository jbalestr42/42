#ifndef PARSINH_H
# define PARSING_H

# include "scop.h"

typedef struct				s_face
{
	int						indice_vertex[3];
	int						indice_texture[3];
	int						indice_normal[3];
}							t_face;

typedef struct				s_uv_list
{
	t_uv					uv;
	struct s_uv_list		*next;
}							t_uv_list;

typedef struct				s_vertex_list
{
	t_vertex				vertex;
	struct s_vertex_list	*next;
}							t_vertex_list;

typedef struct				s_face_list
{
	t_face					face;
	struct s_face_list		*next;
}							t_face_list;

t_vertex_list	*push_vertex(t_vertex_list **begin, float *values);
t_uv_list		*push_uv(t_uv_list **begin, float *values);
t_face_list		*push_face(t_face_list **begin, int *indice_vertex, int *indice_texture, int *indice_normal);

void			setup_mesh_vertex(t_obj_data *obj_data, t_vertex_list *vertex_list);
void			setup_mesh_uv(t_obj_data *obj_data, t_uv_list *uv_list);
void			setup_mesh_faces(t_obj_data *obj_data, t_face_list *face_list);
void			setup_mesh_origin(t_obj_data *obj_data);

char			**ft_strsplit(char const *s, char c);
void			free_split(char **s);
int				ft_strlen_tab(char **tab);

#endif
