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
	double zoom = 10.8, moveX = -0.55, moveY = -0.55; //you can change these to zoom and change posiion
	double cx = 0, cy = 0;   //real and imaginary parts of new and old
	int max_iers = 250; //after how much ierations the function should stop
	int x = 0;
	while (x < WIDTH)
	{
		int y = 0;
		while (y < HEIGHT)
		{
			//calculate the iniial real and imaginary part of z, based on the pixel location and zoom and posiion values
			cx = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + moveX;
			cy = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + moveY;

			double zx = 0, zy = 0;
			if (zx * zx + zy * zy > 4)
				break; // i=0
			int i = 1;
			while (i < max_iers)
			{	double zx_old = zx;
				zx = zx * zx - zy * zy;
				zy = 2 * zx_old * zy;
				zx += cx;
				zy += cy;
				if (zx * zx + zy * zy > 4.0)
					break;
				i++;
			}

			unsigned int color;
			if (i >= max_iers)
				color = create_color(0, 0, 0);
			else if (i > max_iers / 5)
				color = create_color(i * 255 / 10, 0, i * 255 / 10);
			else
				color = create_color(0, 0, i * 255 / 10);

			put_pixel(&e->screen, x, y, color);
			y++;
		}
		x++;
	}
}
