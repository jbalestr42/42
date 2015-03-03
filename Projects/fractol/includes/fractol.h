/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:57:21 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/03 16:45:00 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH			600
# define HEIGHT			440
# define NAME			"Fract'ol"

/*
** Math
*/
# define ABS(x)			((x) < 0 ? -(x) : (x))

/*
** Textures
*/
# define T_COLORS		"textures/pal.xpm"

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

int		mandelbrot(t_env *e, int x, int y, int max_iterations);
int		julia(t_env *e, double cx, double cy, int max_iterations);

#endif
