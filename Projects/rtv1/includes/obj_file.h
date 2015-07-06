#ifndef OBJ_FILE_H
# define OBJ_FILE_H

# include "objects.h"

typedef struct s_vertices	t_vertices;
typedef struct s_vertices	t_normals;

struct			s_vertices
{
	t_vec				vec;
	struct s_vertices	*next;
};

typedef struct			s_obj
{
	t_triangle			triangle;
	struct s_obj		*next;
}						t_obj;

#endif /* !OBJ_FILE_H */
