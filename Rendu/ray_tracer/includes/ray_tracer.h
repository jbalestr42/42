/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 16:23:00 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/13 13:08:17 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include "objects.h"

# define WIDTH			1080 //1440
# define HEIGHT			720 //1080
# define NAME			"Raytracer"
# define NB_KEY_EVENT	2
# define NB_TYPE		6
# define MAX_DBL		1.7976931348623158e+308
# define X_INDENT		0.5 / (double)WIDTH
# define Y_INDENT		0.35 / (double)HEIGHT

/*
** Error messages
*/
# define E_MEM			"Not enough memory."
# define E_MLX			"MLX fail init."
# define E_WIN			"WIN fail init."

/*
** Keys
*/
# define ESC			65307
# define KEY_S			65507

typedef struct s_env	t_env;
typedef void			(key_event)(t_env *e);
typedef void			(mouse_event)(t_env *e);
typedef t_vector		(*normal)(t_mesh *mesh, t_vertex *vertex);
typedef double			(*inter)(t_mesh *mesh, t_ray *ray, t_ray *m_ray);

/*
** ptr : pointer image data
** img : image
** bpp : bit per pixel
** size_line : size of line
** endian : endian
** width : image's width
** height : image's height
** max_size : precompute to avoid obsolete calcul
*/
typedef struct		s_img
{
	void			*ptr;
	char			*img;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	int				max_size;
}					t_img;

typedef enum		e_button_state
{
	NONE, HOVER
}					t_button_state;

/*
** img : image containing none state and hover state
** x and y : image position
** state : current state
*/
typedef struct		s_button
{
	t_img			img;
	int				x_pos;
	int				y_pos;
	int				state;
	int				frame_size;
	mouse_event		*event;
	int				check_box;
	char			*name;
}					t_button;

typedef enum		e_screen_type
{
	MENU, RAY_TRACE, OPTIONS, CHOOSE, LOAD_SCREEN
}					t_screen_type;

typedef struct		s_screen
{
	int				nb_button;
	t_button		*buttons;
	t_img			background;
}					t_screen;

/*
** keycode : key value
** is_press : 1 | 0
** event : event function
*/
typedef struct		s_key
{
	int				keycode;
	int				is_press;
	key_event		*event;
}					t_key;

/*
** mlx : pointer to mlx
** win : pointer to win
** image : image to display on screen
** cur_screen : index of current screen
** screens : all screens
*/
struct				s_env
{
	void			*mlx;
	void			*win;
	double			ambient;
	int				cur_screen;
	double			progress;
	t_button		*cur_button;
	t_screen		*screens;
	t_color			color;
	t_vertex		look_at_point;
	t_vertex		up_left;
	t_cam			cam;
	int				nb_mesh;
	t_mesh			*meshes;
	int				nb_light;
	t_light			*lights;
	int				progressive_load;
	t_key			key_events[NB_KEY_EVENT];
	normal			normals[NB_TYPE];
	inter			inter_tab[NB_TYPE];
}; // il faut enlever les tableaux de pointeur et garder seulement un tab pour les normals

/*
** Inits
*/
t_env		*init_env(char *path);
void		init_events(t_env *e);
void		init_tab(t_env *e);
int			init_screens(t_env *e);
void		init_scene(t_env *e, char *path);
int			init_choose_scene(t_env *e);
void		init_image(void *mlx, t_img *i, int width, int height);
t_vector	init_vec(double x, double y, double z);
void		init_img(void *mlx, t_img *i, int width, int height);
t_img		init_img_xpm(void *mlx, char *path, int width, int height);
t_button	init_button(int x, int y, mouse_event *event, t_img img);

/*
** Display
*/
void		draw_image(t_env *e);
int			save_ppm(t_env *e);
void		refresh_load(t_env *e, double prog);
void		display_choose(t_env *e);
void		display_background(t_button *b, t_img *img);

/*
** Helpers
*/
void		ft_error(int b_exit, t_env *e, char *str);
int			ft_strlen(char *s);
void		ft_putstr(char *s);
char		*ft_strdup(char *s);
void		ft_putnbr(int n);

/*
** Intersections && Normals
*/
int			intersect_mesh(t_env *e, t_ray *ray, t_mesh **mesh, t_vertex *m_ver);
double		inter_sphere(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
double		inter_plan(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
double		inter_cylinder(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
double		inter_cone(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
double		inter_hyperbole(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
double		inter_parabole(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
t_vector	normal_cone(t_mesh *mesh, t_vertex *v);
t_vector	normal_cylinder(t_mesh *mesh, t_vertex *v);
t_vector	normal_plan(t_mesh *mesh, t_vertex *v);
t_vector	normal_sphere(t_mesh *mesh, t_vertex *v);

/*
** Light
*/
t_color		compute_color(t_env *e, t_ray *ray, t_mesh *mesh, int depth, double refr, t_vertex *inter);
t_color		diffuse(t_env *e, t_light *light, t_mesh *mesh, t_ray *ray);
t_color		specular(t_env *e, t_light *light, t_mesh *mesh, t_ray *ray, t_ray *cam_ray);
t_color		reflection(t_env *e, t_mesh *mesh, t_ray *ray_light, t_ray *ray, int depth, double refr);
t_color		refraction(t_env *e, t_mesh *mesh, t_ray *ray_light, t_ray *ray, int depth, double refr);

/*
** Events
*/
int			expose_hook(t_env *e);
int			key_hook_release(int keycode, t_env *e);
int			key_hook_press(int keycode, t_env *e);
void		key_event_esc(t_env *e);
void		key_event_save(t_env *e);
int			mouse_hook_press(int button, int x, int y, t_env *e);
int			mouse_hook_move(int x, int y, t_env *e);
void		mouse_event_ray_trace(t_env *e);
void		mouse_event_leave(t_env *e);
void		mouse_event_options(t_env *e);
void		mouse_event_choose_scene(t_env *e);
void		check_event_load_type(t_env *e);
void		mouse_event_void(t_env *e);

/*
** Math
*/
double		dot(t_vector u, t_vector v);
double		square_length(t_vector u);
double		magnitude(t_vector u);
t_vector	normalize(t_vector u);
double		determinant(double a, double b, double c);
t_vector	add(t_vector u, t_vector v);
t_vector	sub(t_vector u, t_vector v);
t_vector	prod(t_vector u, t_vector v);
t_vector	cross(t_vector u, t_vector v);
t_vector	prod_val(t_vector u, double val);
double		ft_rand(double x);

/*
** Matrix
*/
double		**malloc_matrix(int x, int y);
void		free_matrix(double **matrix, int size);
int			matrix_multiply(double **matrix1, double **matrix2, double **res);
void		copy_matrix(double **matrix1, double **matrix2);
double		**id_matrix(void);
void		inv_trans_matrix(double ***matrix, double x, double y, double z);
void		inv_scale_matrix(double ***matrix, double a, double b, double c);
void		inv_rot_matrix_x(double ***matrix, double theta);
void		inv_rot_matrix_y(double ***matrix, double theta);
void		inv_rot_matrix_z(double ***matrix, double theta);
void		trans_matrix(double ***matrix, double x, double y, double z);
t_vertex	transform_pos(double **m, t_vertex *p);
t_vector	transform_dir(double **m, t_vector *p);
t_vertex	transform_normal(double **m, t_vector *p);
void		transform_matrix(double **matrix1, double **matrix2);
void		compute_matrix(t_mesh *mesh);

# include "perlin.h"

#endif /* !RAY_TRACER_H */
