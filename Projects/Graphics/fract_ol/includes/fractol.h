/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:57:21 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/27 20:44:32 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH			800
# define HEIGHT			600
# define HALF_WIDTH		WIDTH / 2
# define HALF_HEIGHT	HEIGHT / 2
# define NAME			"Fract'ol"
# define NB_FRACTAL		12
# define NB_PAL			7

/*
** Math
*/
# define ABS(x)			((x) < 0 ? -(x) : (x))

/*
** Textures
*/
# define T_PAL			"textures/pal.xpm"
# define T_PAL1			"textures/pal1.xpm"
# define T_PAL2			"textures/pal2.xpm"
# define T_PAL3			"textures/pal3.xpm"
# define T_PAL4			"textures/pal4.xpm"
# define T_PAL5			"textures/pal5.xpm"
# define T_PAL6			"textures/pal6.xpm"

/*
** Keys
*/
# define ESC			53
# define LEFT			123
# define UP				126
# define RIGHT			124
# define DOWN			125
# define PLUS			69
# define MINUS			78
# define TAB			48
# define SHIFT			257
# define KEY_R			15
# define KEY_1			18
# define KEY_2			19

typedef struct s_env	t_env;
typedef int				(*t_fractal)(t_env *e, int x, int y, int mi);

typedef struct	s_img
{
	void		*ptr;
	char		*img;
	int			bpp;
	int			size_line;
	int			endian;
	int			max_size;
	int			width;
	int			height;
}				t_img;

typedef struct	s_util
{
	double		old_zx;
	double		old_zy;
	double		cx;
	double		cy;
	double		zx;
	double		zy;
	double		zxx;
	double		zyy;
	double		d;
	double		cld;
	int			cln;
	int			last_iter;
	int			i;
}				t_util;

struct			s_env
{
	void		*mlx;
	void		*win;
	t_img		screen;
	double		offset_zoom_x;
	double		offset_zoom_y;
	double		offset_x;
	double		offset_y;
	double		mouse_x;
	double		mouse_y;
	double		zoom;
	double		c0x;
	double		c0y;
	double		zoom_width;
	double		zoom_height;
	double		julia_cx;
	double		julia_cy;
	int			click_pos_x;
	int			click_pos_y;
	int			move_pos_x;
	int			move_pos_y;
	int			current_pal;
	t_img		pals[NB_PAL];
	int			current_fractal;
	t_fractal	fractal_fun[NB_FRACTAL];
	t_util		u;
};

/*
** Hooks
*/
int				key_hook_press(int keycode, t_env *e);
int				mouse_hook_move(int x, int y, t_env *e);
int				mouse_hook_press(int button, int x, int y, t_env *e);
int				expose_hook(t_env *e);
void			key_press_color_fractal(int keycode, t_env *e);

/*
** Init
*/
void			ft_envdel(t_env *e);
t_env			*ft_envnew(void);
void			init_images(t_env *e);
void			init_var(t_env *e);
void			init_mandelbrot(t_env *e, int x, int y);
void			init_julia(t_env *e, int x, int y);
void			update_zoom(t_env *e);

void			draw(t_env *e);
void			put_pixel(t_img *img, int x, int y, unsigned int color);
unsigned int	get_color_from_img(t_env *e, double it, int max_iterations);
unsigned int	create_color(int r, int g, int b);

int				mandelbrot(t_env *e, int x, int y, int max_iterations);
int				mandelbrot_bof60(t_env *e, int x, int y, int max_iterations);
int				mandelbrot_bof61(t_env *e, int x, int y, int max_iterations);
int				mandelbrot_broken(t_env *e, int x, int y, int max_iterations);
int				mandelbrot_tunnel(t_env *e, int x, int y, int max_iterations);
int				julia(t_env *e, int x, int y, int max_iterations);
int				julia_bof60(t_env *e, int x, int y, int max_iterations);
int				julia_bof61(t_env *e, int x, int y, int max_iterations);
int				julia_broken(t_env *e, int x, int y, int max_iterations);
int				julia_tunnel(t_env *e, int x, int y, int max_iterations);
int				burning_ship(t_env *e, int x, int y, int max_iterations);
int				newton(t_env *e, int x, int y, int max_iterations);

#endif
