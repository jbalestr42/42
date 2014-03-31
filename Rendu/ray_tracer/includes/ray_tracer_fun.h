/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer_fun.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 19:12:40 by jbalestr          #+#    #+#             */
/*   Updated: 2014/03/27 20:12:05 by fcorbel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_FUN_H
# define RAY_TRACER_FUN_H

# include "objects.h"
# include "obj_file.h"
# include "light.h"

# define WIDTH			1080
# define HEIGHT			720
# define NAME			"Raytracer"
# define NB_KEY_EVENT	7
# define NB_TYPE		7
# define NB_EFFECT		7
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
# define KEY_S			115
# define KEY_R			114
# define KEY_1			49
# define KEY_2			50
# define KEY_3			51
# define KEY_4			52

typedef struct s_env	t_env;
typedef void			(t_key_event)(t_env *e);
typedef void			(t_mouse_event)(t_env *e);
typedef struct s_vertex	(*t_normal)(t_mesh *mesh, t_vertex *vertex);
typedef double			(*t_inter)(t_mesh *mesh, t_ray *ray, t_ray *m_ray);
typedef struct s_color	(*t_effect)(t_vertex var, t_color pix1, t_color pix2,
							int n);

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
	t_mouse_event	*event;
	int				check_box;
	char			*name;
}					t_button;

typedef enum		e_screen_type
{
	RAY_TRACE, OPTIONS, CHOOSE, LOAD_SCREEN, MENU
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
	t_key_event		*event;
}					t_key;

/*
** anti aliasing struct
*/
typedef struct		s_aa
{
	int				x;
	int				y;
	double			dx;
	double			dy;
	t_ray			*ray;
	t_mesh			**mesh;
	t_vertex		*inter;
}					t_aa;

typedef struct		s_lst
{
	int				fd;
	struct s_lst	*next;
}					t_lst;

/*
** Environement struct
*/
struct				s_env
{
	void			*mlx;
	void			*win;
	double			ambient;
	int				cur_screen;
	int				cur_panel;
	int				nb_panel;
	t_aa			aa;
	int				progressive_load;
	int				ocean;
	int				aa_active;
	int				cell_shading;
	int				attenuate;
	int				video;
	t_img			vid[180];
	t_img			img_tmp;
	t_obj			*obj;
	int				nb_obj;
	t_button		*cur_button;
	t_screen		*screens;
	t_color			color;
	t_vertex		look_at_point;
	t_vertex		up_left;
	t_cam			cam;
	int				nb_mesh;
	int				nb_mesh_malloc;
	t_mesh			*meshes;
	int				nb_light;
	int				nb_light_malloc;
	int				check_parse;
	int				i_pos;
	t_light			*lights;
	t_lst			*start;
	t_key			key_events[NB_KEY_EVENT];
	t_normal		normals[NB_TYPE];
	t_inter			inter_tab[NB_TYPE];
	t_effect		effects[NB_EFFECT];
};

#endif
