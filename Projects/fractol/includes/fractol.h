/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:57:21 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/03 23:13:52 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH			800
# define HEIGHT			600
# define HALF_WIDTH		WIDTH / 2
# define HALF_HEIGHT		HEIGHT / 2
# define NAME			"Fract'ol"

/*
** Math
*/
# define ABS(x)			((x) < 0 ? -(x) : (x))

/*
** Textures
*/
# define T_COLORS		"textures/pal2.xpm"
# define T_HSV			"textures/hsv.xpm"

/*
** Keys
*/
# define ESC			65307
# define LEFT			65361
# define UP			65362
# define RIGHT			65363
# define DOWN			65364

typedef struct	s_fractal
{
	double	zoom;
	double	move_x;
	double	move_y;

}		t_fractal;

typedef struct	s_img
{
	void	*ptr;
	char	*img;
	int	bpp;
	int	size_line;
	int	endian;
	int	max_size;
	int	width;
	int	height;
}		t_img;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	screen;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int	click_pos_x;
	int	click_pos_y;
	int	move_pos_x;
	int	move_pos_y;
	t_img	pal;
	t_img	hsv;
}		t_env;

/*
** Hooks
*/
int		key_hook_press(int keycode, t_env *e);
int		mouse_hook_move(int x, int y, t_env *e);
int		mouse_hook_press(int button, int x, int y, t_env *e);
int		expose_hook(t_env *e);

/*
**
*/
void		ft_envdel(t_env *e);
t_env *		ft_envnew(void);

void		draw(t_env *e);
void		put_pixel(t_img *img, int x, int y, unsigned int color);
unsigned int	get_color_from_img(t_img *img, double it, int max_iterations);
unsigned int	get_color_hsv(t_img *img, double x, double y);
unsigned int	create_color(int r, int g, int b);

int		mandelbrot(t_env *e, int x, int y, int max_iterations);
int		mandelbrot_broken(t_env *e, int x, int y, int max_iterations);
int		mandelbrot_tunnel(t_env *e, int x, int y, int max_iterations);
int		julia(t_env *e, double cx, double cy, int max_iterations);
int		burning_ship(t_env *e, double cx, double cy, int max_iterations);
int		newton(t_env *e, double cx, double cy, int max_iterations);

#endif
