#include "fractol.h"

int mandelbrot(t_env *e, int x, int y, int max_iterations)
{
	double cx = 1.5 * (x - e->move_pos_x) / (0.5 * e->zoom * WIDTH) + e->offset_x;
	double cy = (y - e->move_pos_y) / (0.5 * e->zoom * HEIGHT) + e->offset_y;
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

int julia(t_env *e, double x, double y, int max_iterations)
{
	double cx = -0.7+ e->move_pos_x / (double)WIDTH;	//0.285
	double cy = 0.27015 - (e->move_pos_y / (double)HEIGHT / 5);	//0.01
	double zx = 1.5 * (x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->offset_x;
	double zy = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->offset_y;
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

