/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:12:43 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 20:16:15 by jbalestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include "ray_tracer_fun.h"

/*
** Inits
*/
t_env		*init_env(void);
void		init_events(t_env *e);
void		init_tab(t_env *e);
int			init_screens(t_env *e);
int			init_scene(t_env *e, char *path);
int			init_choose_scene(t_env *e);
void		init_image(void *mlx, t_img *i, int width, int height);
t_vector	init_vec(double x, double y, double z);
void		init_img(void *mlx, t_img *i, int width, int height);
t_img		init_img_xpm(void *mlx, char *path, int width, int height);
t_button	init_button(int x, int y, t_mouse_event *event, t_img img);
int			open_obj(t_env *e, char *path);
t_compute	init_compute(t_ray ray, t_mesh *m, t_vertex i, t_ray ray_light);
t_lst		*lst_add(int fd, t_lst *l);
t_lst		*lst_new(void);
void		del_parse(t_env *e);

/*
** Display
*/
void		draw_image(t_env *e);
int			save_ppm(t_env *e);
void		refresh_load(t_env *e, double prog);
void		display_choose(t_env *e);
void		display_background(t_button *b, t_img *img);
t_color		compute_aa(t_env *e, t_ray *ray, t_mesh **mesh, t_vertex *inter);
void		display_video(t_env *e, t_img *vid);
void		draw_pipe(t_env *e, int x);
void		draw_image(t_env *e);
void		escape_screen(t_env *e);

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
int			intersect_mesh(t_env *e, t_ray *ray, t_mesh **mesh,
							t_vertex *m_ver);
double		inter_sphere(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
double		inter_plan(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
double		inter_cylinder(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
double		inter_cone(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
double		inter_hyperbole(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
double		inter_parabole(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
double		inter_triangle(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
t_vector	normal_cone(t_mesh *mesh, t_vertex *v);
t_vector	normal_cylinder(t_mesh *mesh, t_vertex *v);
t_vector	normal_plan(t_mesh *mesh, t_vertex *v);
t_vector	normal_sphere(t_mesh *mesh, t_vertex *v);
t_vertex	normal_parabole(t_mesh *mesh, t_vertex *v);
t_vertex	normal_hyperbole(t_mesh *mesh, t_vertex *v);
t_vertex	normal_triangle(t_mesh *mesh, t_vertex *v);

/*
** Light
*/
t_color		compute_color(t_env *e, t_compute c, int depth, double refr);
t_color		diffuse(t_env *e, t_light *light, t_mesh *mesh, t_ray *ray);
t_color		specular(t_env *e, t_light *light, t_compute c);
t_color		reflection(t_env *e, t_compute c, int depth, double refr);
t_color		refraction(t_env *e, t_compute c, int depth, double refr);

/*
** Events
*/
int			expose_hook(t_env *e);
int			key_hook_release(int keycode, t_env *e);
int			key_hook_press(int keycode, t_env *e);
void		key_event_esc(t_env *e);
void		key_event_save(t_env *e);
void		key_event_run_video(t_env *e);
void		key_event_b_and_w(t_env *e);
void		key_event_sepia(t_env *e);
void		key_event_negative(t_env *e);
void		key_event_none(t_env *e);
int			mouse_hook_press(int button, int x, int y, t_env *e);
int			mouse_hook_move(int x, int y, t_env *e);
void		mouse_event_ray_trace(t_env *e);
void		mouse_event_leave(t_env *e);
void		mouse_event_options(t_env *e);
void		mouse_event_choose_scene(t_env *e);
void		mouse_event_void(t_env *e);
void		mouse_event_ls(t_env *e);
void		mouse_event_rs(t_env *e);
void		mouse_event_yolo(t_env *e);
void		check_event_back(t_env *e);
void		check_event_ocean(t_env *e);
void		check_event_aa(t_env *e);
void		check_event_cell_shading(t_env *e);
void		check_event_attenuate(t_env *e);
void		check_event_video(t_env *e);

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
void		compute_up_left(t_env *e);
void		compute_ray(t_env *e, t_ray *r, int x, int y);
void		launch_ray(t_env *e, int x, int y);
t_color		add_col_col(t_color col1, t_color col2);
t_color		prod_col_col(t_color col1, t_color col2);
t_color		add_col_val(t_color col1, double value);
t_color		prod_col_val(t_color col1, double value);
t_color		init_color(double r, double g, double b);

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

#endif
