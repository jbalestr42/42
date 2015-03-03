#include "fractol.h"
#include <stdio.h>
#include <math.h>
#include <mlx.h>

static unsigned int	create_color(int r, int g, int b)
{
	int color;
	color = (b + (g << 8) + (r << 16));
	return (color);
}

static unsigned int	get_color_from_img(t_img *img, int it, int max_iterations)
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

static void		put_pixel(t_img *img, int x, int y, unsigned int color)
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
	int max_iterations = 50;
//	int max_iterations = sqrt(ABS(2 * sqrt(ABS(1 - sqrt(5 * e->zoom))))) * 66.5;
	printf("%f %f\n", e->offset_x, e->offset_y);
	int x = 0;
	while (x < WIDTH)
	{
		int y = 0;
		while (y < HEIGHT)
		{
			//calculate the iniial real and imaginary part of z, based on the pixel location and zoom and posiion values
			int i = mandelbrot(e, x, y, max_iterations);
			//int i = julia(e, x, y, max_iterations);

			unsigned int color;
			// use the mlx converter color function
			/*if (i >= max_iterations)
				color = create_color(250, 0, 0);
			else if (i > max_iterations / 5)
				color = create_color(i * 255 / 10, 0, i * 255 / 10);
				//sin(it / 7.0),cos(it / 5.0),sin(it / 9.0 + 3.14 / 4.0)
			else
				color = create_color(0, 0, i * 255 / 10);
*/
			if (i >= max_iterations)
				color = create_color(0, 0, 0);
			else
				color = create_color(0, 0, 255 - i % 256);
			color = get_color_from_img(&e->pal, i, max_iterations);
			put_pixel(&e->screen, x, y, color);
			y++;
		}
		x++;
	}
}
