#include "fractol.h"

static unsigned int create_color(int r, int g, int b)
{
	return (b + (g << 8) + (r << 16));
}

static void put_pixel(t_img *img, int x, int y, unsigned int color)
{
	int i = y * img->size_line + x * img->bpp;
	if (i > 0 && i < img->max_size)
	{
		img->img[i] = color;
		img->img[i + 1] = (color >> 8);
		img->img[i + 2] = (color >> 16);
	}
}

void draw(t_env *e)
{
	int max_iterations = 150; //after how much ierations the function should stop
	int x = 0;
	while (x < WIDTH)
	{
		int y = 0;
		while (y < HEIGHT)
		{
			//calculate the iniial real and imaginary part of z, based on the pixel location and zoom and posiion values
			//int i = mandelbrot(max_iterations);
			int i = julia(x, y, max_iterations);

			unsigned int color;
			// use the mlx converter color function
			/*if (i >= max_iterations)
				color = create_color(250, 0, 0);
			else if (i > max_iterations / 5)
				color = create_color(i * 255 / 10, 0, i * 255 / 10);
			else
				color = create_color(0, 0, i * 255 / 10);
*/
			if (i >= max_iterations)
				color = create_color(0, 0, 0);
			else
				color = create_color(i % 150, 0, i % 256);
			put_pixel(&e->screen, x, y, color);
			y++;
		}
		x++;
	}
}
