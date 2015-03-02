#include "fractol.h"

int mandelbrot(int x, int y, int max_iterations)
{
	double zoom = 1, moveX = 0, moveY = 0;
	double cx = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH) + moveX;
	double cy = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT) + moveY;
	double zx = 0, zy = 0;
	int i = 1;
	while (i < max_iterations)
	{
		double zx_old = zx;
		zx = zx * zx - zy * zy;
		zy = 2 * zx_old * zy;
		zx += cx;
		zy += cy;
		if (zx * zx + zy * zy > 4.0)
			break;
		i++;
	}
	return (i);
}

int julia(double x, double y, int max_iterations)
{
	double zoom = 0.6, moveX = 1, moveY = 1;
	double zx = 0, zy = 0;
	// faire varier les parametre avec la souris
	double cx = -0.7;	//0.285
	double cy = 0.27015;	//0.01
	zx = x / (zoom * (WIDTH / 2)) - moveX / zoom;
	zy = y / (zoom * (HEIGHT / 2)) - moveY / zoom;
	int i = 1;
	while (i < max_iterations)
	{
		double old_zx = zx;
		zx = zx * zx - zy * zy + cx;
		zy = 2 * zy * old_zx + cy;
		if (zx * zx + zy * zy > 4.0)
			break;
		i++;
	}
	return (i);
}

