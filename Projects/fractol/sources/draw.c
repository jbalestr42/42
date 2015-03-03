#include "fractol.h"
#include <stdio.h>
#include <math.h>
#include <mlx.h>

unsigned int	create_color(int r, int g, int b)
{
	int color;
	color = (b + (g << 8) + (r << 16));
	return (color);
}

unsigned int	get_color_hsv(t_img *img, double x, double y)
{
	int vx = (double)(x * 100.0 + (double)HALF_WIDTH);
	int vy = (double)(y *100.0 + (double)HALF_HEIGHT);
	unsigned int color;
	int i = vy * img->size_line + vx * img->bpp;
	if (i > 0 && i < img->max_size)
	{
		color = img->img[i + 0];
		color += img->img[i + 1] << 8;
		color += img->img[i + 2] << 16;
	}
	return color;
}

unsigned int	get_color_from_img(t_img *img, double it, int max_iterations)
{
	unsigned int color;
	int i = (float)it / (float)max_iterations * img->width;
	i *= img->bpp;
	if (i > 0 && i < img->max_size)
	{
		color = img->img[i + 0];
		color += img->img[i + 1] << 8;
		color += img->img[i + 2] << 16;
	}
	else
		color = 0;
	return (color);
}

void		put_pixel(t_img *img, int x, int y, unsigned int color)
{
	int i = y * img->size_line + x * img->bpp;
	if (i > 0 && i < img->max_size)
	{
		img->img[i + 0] = color;
		img->img[i + 1] = (color >> 8);
		img->img[i + 2] = (color >> 16);
	}
}

void			draw(t_env *e)
{
	//int max_iterations = 28;
	int max_iterations = sqrt(ABS(2 * sqrt(ABS(1 - sqrt(5 * e->zoom))))) * 66.5;
	printf("%f %f\n", e->offset_x, e->offset_y);
	printf("%d %d\n", e->move_pos_x, e->move_pos_y);
	printf("%f\n", e->zoom);
	printf("%d\n", max_iterations);
	int color;
	int x = 0;
	while (x < WIDTH)
	{
		int y = 0;
		while (y < HEIGHT)
		{
			//calculate the iniial real and imaginary part of z, based on the pixel location and zoom and posiion values
			//color = newton(e, x, y, max_iterations);
			//color = julia(e, x, y, max_iterations);
			//color = burning_ship(e, x, y, max_iterations);
			color = mandelbrot(e, x, y, max_iterations);
			//color = mandelbrot_broken(e, x, y, max_iterations);
			//color = mandelbrot_tunnel(e, x, y, max_iterations);

			put_pixel(&e->screen, x, y, color);
			y++;
		}
		x++;
	}
}
