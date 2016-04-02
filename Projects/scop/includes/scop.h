#ifndef SCOP_H
# define SCOP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <time.h>
# include <GL/glew.h>
# include <GLUT/glut.h>
//# include <OpenGL/gl.h>
# include <GLUT/freeglut.h>

# define WINDOW_TITLE_PREFIX "Scop"
# define NUM_BUFFER 4
# define NUM_SHADER 2
# define NUM_UNIFORM 5
# define POSITION_VB 0
# define INDEX_VB 1
# define TEXCOORD_VB 2
# define NORMAL_VB 3

# define KEY_COUNT 9
# define KEY_FORWARD 0
# define KEY_BACKWARD 1
# define KEY_LEFT 2
# define KEY_RIGHT 3
# define KEY_UP 4
# define KEY_DOWN 5
# define KEY_P 6
# define KEY_M 7
# define KEY_L 8

static const double PI = 3.14159265358979323846;

typedef struct			s_uv
{
	float				position[2];
}						t_uv;

typedef struct			s_vector
{
	float				v[3];
}						t_vector;

typedef struct			s_vertex
{
	float				position[4];
	float				uv[2];
	float				color[4];
}						t_vertex;

typedef struct			s_matrix
{
	float				m[16];
}						t_matrix;

typedef struct			s_obj_data
{
	t_vector			origin;
	t_uv				*obj_uvs;
	t_vertex			*obj_vertices;
	t_vertex			*vertices;
	int					*indices;
	int					face_count;
	int					indice_count;
	int					vertex_count;
	int					uv_count;
}						t_obj_data;

typedef struct			s_mesh
{
	GLuint				vertex_array_object;
	GLuint				vertex_buffer_object[NUM_BUFFER];
	int					indice_count;
	t_vector			origin;
	float				rotation;
	float				scale;
	float				transparency;
	t_matrix			transform;
	int					transition;
}						t_mesh;

typedef struct			s_shader
{
	GLuint				program;
	GLuint				shaders[NUM_SHADER];
	GLuint				uniforms[NUM_UNIFORM];
}						t_shader;

typedef struct			s_texture
{
	GLuint				texture;
	int					width;
	int					height;
	unsigned char		*data;
}						t_texture;

typedef struct			s_key
{
	unsigned char		code;
	int					is_active;
}						t_key;

typedef struct			s_camera
{
	float				fov;
	float				near_plane;
	float				far_plane;
	t_vector			forward;
	t_vector			right;
	t_vector			up;
	float				rotation[2];
	t_matrix			translation;
}						t_camera;

typedef struct			s_env
{
	t_mesh				*mesh;
	t_shader			*shader;
	t_texture			*texture;
	clock_t				last_time;
	int					last_mouse_x;
	int					last_mouse_y;
	int					mouse_x;
	int					mouse_y;
	int					frame_count;
	int					wnd_width;
	int					wnd_height;
	int					wnd_handle;
	t_matrix			projection;
	t_matrix			view;
	t_camera			camera;
	t_key				keys[KEY_COUNT];
}						t_env;

// Global variable
t_env		env;

// Init
void		init_env(t_env * env);
void		init_openGL(int, char*[]);
void		init_window(int, char*[]);
void		exit_on_GLerror(const char* error_message);
GLuint		load_shader(const char* filename, GLenum shader_type);
int			load_mesh(t_obj_data *obj_data, char const *filename);

t_mesh		*create_mesh(char const *filename);
void		destroy_mesh(t_mesh *mesh);
void		draw_mesh(t_mesh *mesh);
void		update_mesh(t_mesh *mesh, float frametime);
t_shader	*create_shader(void);
void		destroy_shader(t_shader *shader);
t_texture	*create_texture(char const *filename);
void		destroy_texture(t_texture *texture);
void		destroy_obj_data(t_obj_data *obj_data);
void		clear(void);
void		draw(void);

void		update_camera_rotation(float frametime);
void		update_camera_translation(float frametime);

// Callback functions
void		resize_function(int, int);
void		render_function(void);
void		timer_function(int);
void		idle_function(void);
void		keyboard_input_press(unsigned char key, int x, int y);
void		keyboard_input_release(unsigned char key, int x, int y);
void		mouse_move_input(int x, int y);

// Math
extern const t_matrix IDENTITY_MATRIX;
float		cotangent(float angle);
float		degrees_to_radians(float degrees);
float		radians_to_degrees(float radians);

void		init_vector(t_vector *v, float x, float y, float z);
void		normalize(t_vector * vector);
float		magnitude(t_vector * vector);
void		cross_product(t_vector *res, t_vector * v1, t_vector *v2);
float		dot(t_vector * v1, t_vector * v2);
void		add_vector(t_vector *res, t_vector *v1, t_vector *v2, float factor);
t_vector	multiply_matrix_vector(const t_matrix * m, const t_vector * v);

t_matrix	multiply_matrices(const t_matrix* m1, const t_matrix* m2);
void		rotate_about_x(t_matrix* m, float angle);
void		rotate_about_y(t_matrix* m, float angle);
void		rotate_about_z(t_matrix* m, float angle);
void		scale_matrix(t_matrix* m, float x, float y, float z);
void		translate_matrix(t_matrix* m, t_vector *v);
t_matrix	create_projection_matrix(float fovy, float aspect_ratio, float near_plane, float far_plane);
void		create_view_matrix(t_matrix * view, t_vector * up, t_vector * right, t_vector * forward);

#endif
