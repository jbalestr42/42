/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 12:06:08 by jbalestr          #+#    #+#             */
/*   Updated: 2014/02/13 13:21:38 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include "objects.h"
# include "obj_file.h"

# define WIDTH			900
# define HEIGHT			600
# define NAME			"Raytracer v1.0"
# define NB_KEY_EVENT	1
# define NB_TYPE		5
# define MAX_DBL		1.7976931348623158e+308

/*
** Keys
*/
# define ESC			65307

typedef struct s_env	t_env;
typedef void			(key_event)(t_env *e);

typedef struct		s_key
{
	int				keycode;
	int				is_press;
	key_event		*event;
}					t_key;

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

typedef double		(*inter)(t_object *obj, t_ray *ray);

struct				s_env
{
	void			*mlx;
	void			*win;
	double			x_ratio;
	double			y_ratio;
	int				nb_object;
	int				nb_light;
	int				nb_obj;
	t_obj			*obj;
	t_light			*lights;
	t_vec			pos_plan;
	t_object		*objects;
	t_img			screen;
	inter			get_inter[NB_TYPE];
	t_key			key_events[NB_KEY_EVENT];
	t_cam			cam;
};

/*
** Read scene
*/
t_color		read_color(t_env *e, char *str);
t_light		read_light(t_env *e, char *s);
t_object	read_cylinder(t_env *e, char *s);
t_object	read_cone(t_env *e, char *s);
t_object	read_sphere(t_env *e, char *s);
t_object	read_plan(t_env *e, char *s);
t_object	read_triangle(t_env *e, char *s);

/*
** Helpers
*/
void		ft_error(int exit, t_env *e, char *str);
void		free_split(char **s);
void		del_env(t_env *e);
int			ft_strlen(char *s);
int			ft_strlen_tab(char **tab);
t_env		*init_env(char *path);
t_vec		init_vec(double x, double y, double z);
void		init_events(t_env *e);
void		init_types(t_env *e);
int			init_scene(t_env *e, char *path);
void		init_screen(void *mlx, t_img *img, int width, int height);
int			ft_atoi(const char *str);
char		**ft_strsplit(char const *s, char c);
void		draw_view(t_env *e);

/*
** Math
*/
void		add_vec(t_vec *res, t_vec *a, t_vec *b);
void		sub_vec(t_vec *res, t_vec *a, t_vec *b);
void		mul_vec(t_vec *res, t_vec *a, t_vec *b);
void		mul_vec_val(t_vec *res, t_vec *p, double val);
double		dot_product(t_vec *a, t_vec *b);
double		square_length(t_vec *p);
double		magnitude(t_vec *p);
void		normalize(t_vec *p);
double		determinant(double a, double b, double c);
double		compute_inter(t_env *e, t_ray *ray, t_object **obj);
void		compute_light(t_env *e, t_vec *inter_v, t_ray *ray, t_object *obj);
t_color		compute_diff(t_light *li, t_object *obj, t_vec *vi, double shade);
double		inter_sphere(t_object *obj, t_ray *ray);
double		inter_plan(t_object *obj, t_ray *ray);
double		inter_cylinder(t_object *obj, t_ray *ray);
double		inter_cone(t_object *obj, t_ray *ray);
double		inter_triangle(t_object *obj, t_ray *ray);
t_vec		normal_sphere(t_sphere *sph, t_vec *vi);
t_vec		normal_cone(t_cone *con, t_vec *vi);
t_vec		normal_cylinder(t_cylinder *cyl, t_vec *vi);
t_color		diffuse_sphere(t_light *li, t_object *obj, t_vec *vi, double shade);
t_color		diffuse_plan(t_light *li, t_object *obj, t_vec *vi, double shade);
t_color		diffuse_cyl(t_light *li, t_object *obj, t_vec *vi, double shade);

/*
** Init obj
*/
t_vertices	*new_vertex(t_vec v);
void		push_vertex(t_vertices **begin, t_vertices *new);
t_obj		*new_triangle(t_triangle t);
void		push_triangle(t_obj **begin, t_obj *new);
double		ft_atod(char *s);
int			open_obj(t_env *e, char *path);

/*
** Hooks
*/
int			key_hook_press(int keycode, t_env *e);
int			key_hook_release(int keycode, t_env *e);
int			expose_hook(t_env *e);
int			loop_hook(t_env *e);

/*
** Key events
*/
void		key_event_esc(t_env *e);

#endif /* !RAY_TRACER_H */
