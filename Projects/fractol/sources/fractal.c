#include "fractol.h"
#include <math.h>

int mandelbrot_broken(t_env *e, int x, int y, int max_iterations)
{
	double cx = 1.5 * (x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->offset_x;
	double cy = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->offset_y;
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
	double nu = i + 1 - log(log(zx + zy)) / log(2);
	return (get_color_from_img(&e->pal, nu, max_iterations));
}

int mandelbrot_tunnel(t_env *e, int x, int y, int max_iterations)
{
	double cx = 1.5 * (x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->offset_x;
	double cy = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->offset_y;
	double zx = 0, zy = 0;
	int i = 1;
	while (i < max_iterations)
	{
		double zx_old = zx;
		zx = zx * zx - zy * zy;
		zy = 2 * zx_old * zy;
		zx += cx;
		zy += cy;
		if (zx * zx + zy * zy > 1.0)
			break;
		i++;
	}
	double nu = i - log(log(sqrt(zx*zx + zy*zy))) / log(2.0);
	return (get_color_from_img(&e->pal, nu, max_iterations));
}

int mandelbrot(t_env *e, int x, int y, int max_iterations)
{
	double cx = 1.5 * (x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->offset_x;
	double cy = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->offset_y;
	double zx = 0, zy = 0;
	double d = 0.0;
	int i = 1;
	while (i < max_iterations)
	{
		double zx_old = zx;
		double zy_old = zy;
		zx = zx * zx - zy * zy;
		zy = 2 * zx_old * zy;
		zx += cx;
		zy += cy;
		d += sqrt((zx_old - cx) * (zx_old - cx) + (zy_old - cy) * (zy_old - cy));
		if (zx * zx + zy * zy > 4.0)
			break;
		i++;
	}
	//double nu = i - log(log(sqrt(zx*zx + zy*zy))) / log(2.0);
	if (i >= max_iterations)
		return (get_color_hsv(&e->hsv, zx - cx, zy - cy));
	return (get_color_from_img(&e->pal, d, max_iterations));
}

int julia(t_env *e, double x, double y, int max_iterations)
{
	double cx = -0.7;// + e->move_pos_x / (double)WIDTH;	//02.285
	double cy = 0.27015;// - (e->move_pos_y / (double)HEIGHT / 5);	//0.01
	double zx = 1.5 * (x - HALF_WIDTH) / (0.5 * e->zoom * WIDTH) + e->offset_x;
	double zy = (y - HALF_HEIGHT) / (0.5 * e->zoom * HEIGHT) + e->offset_y;
	double zxx = 0, zyy = 0;
	int i = 1;
	while (i < max_iterations)
	{
		zxx = zx * zx;
		zyy = zy * zy;
		double old_zx = zx;
		zx = zxx - zyy + cx;
		zy = 2 * zy * old_zx + cy;
		if (zxx + zyy > 4.0)
			break;
		i++;
	}
	return (get_color_from_img(&e->pal, i, max_iterations));
}

int burning_ship(t_env *e, double x, double y, int max_iterations)
{
	double cx = 1.5 * (x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->offset_x;
	double cy = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->offset_y;
	double zx = 0, zy = 0;
	int i = 1;
	while (i < max_iterations)
	{
		double old_zx = zx;
		zx = zx * zx - zy * zy - cx;
		zy = 2 * fabs(zy * old_zx) + cy;
		if (zx * zx + zy * zy > 4.0)
			break;
		i++;
	}
	return (get_color_from_img(&e->pal, i, max_iterations));
}

int newton(t_env *e, double x, double y, int max_iterations)
{
	double cx = 1.5 * (x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->offset_x;
	double cy = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->offset_y;
	double zx = cx, zy = cy;
	int i = 1;
	while (i < max_iterations)
	{
		double xx = zx*zx;
		double yy = zy*zy;
		double d = 3.0*((xx - yy)*(xx - yy) + 4.0*xx*yy);
		if (d == 0.0)
		{
			d = 0.000001;
			break;
		}
		double tmp=zx;
		zx = (2.0/3.0)*zx + (xx - yy)/d;
		zy = (2.0/3.0)*zy - 2.0*tmp*zy/d;
		i++;
	}
	unsigned int color;
	if (zx>0.0)
		color = create_color(255,0,0);
	else
	{
		if ((zx<-0.3) && (zy>0.0))
			color = create_color(0,255,0);
		else
			color = create_color(0,0,255);
	}
	return (color);
}
