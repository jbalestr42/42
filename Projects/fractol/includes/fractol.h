/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbalestr <jbalestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 19:57:21 by jbalestr          #+#    #+#             */
/*   Updated: 2015/03/02 18:40:21 by pciavald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH			1580
# define HEIGHT			800
# define NAME			"Fract'ol"

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
}		t_img;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	screen;
}		t_env;

/*
** Hooks
*/
int		key_hook_press(int keycode, t_env *e);
int		expose_hook(t_env *e);

/*
**
*/
void		ft_envdel(t_env *e);
t_env *		ft_envnew(void);

void		draw(t_env *e);

int		mandelbrot(int x, int y, int max_iterations);
int		julia(double cx, double cy, int max_iterations);

#endif
