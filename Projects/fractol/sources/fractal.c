#include "fractol.h"
#include <math.h>
#include <stdio.h>

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

double mdist(double cx, double cy , int iter_max)
{ 
	int i; 
	double x = cx, y = cy, //Z0 = c, 
		   xp = 1, yp = 0, // zp = 1
		   nz, // temporary 
		   nzp,
		   a; // abs(z)

	for (i = 1; i <= iter_max; i++)
	{ //zp = 2*z*zp + 1 = xp + yp*i;
		nz = 2*(x*xp - y*yp) + 1; 
		yp = 2*(x*yp + y*xp); 
		xp = nz;
		//z = z*z + c = x+y*i
		nz = x*x - y*y + cx; 
		y = 2*x*y + cy; 
		x = nz; 
		//
		nz = x*x + y*y; 
		nzp = xp*xp + yp*yp;
		if (nzp > 1e60 || nz > 1e60) break;
	}
	a=sqrt(nz);
	//distance = 2 * |Zn| * log|Zn| / |dZn|
	return 2* a*log(a)/sqrt(nzp); 
}

unsigned int GiveRainbowColor(double position)
{
	if (position>1)position=position-(int)position;
	// if position > 1 then we have repetition of colors
	// it maybe useful
	int R, G, B;// byte
	int nmax=6;// number of color bars
	double m=nmax* position;
	int n=(int)m; // integer of m
	double f=m-n;  // fraction of m
	int t = (int)f*255;
	switch( n){
		case 0: {
					R = 255;
					G = t;
					B = 0;
					break;
				};
		case 1: {
					R = 255 - t;
					G = 255;
					B = 0;
					break;
				};
		case 2: {
					R = 0;
					G = 255;
					B = t;
					break;
				};
		case 3: {
					R = 0;
					G = 255 - t;
					B = 255;
					break;
				};
		case 4: {
					R = t;
					G = 0;
					B = 255;
					break;
				};
		case 5: {
					R = 255;
					G = 0;
					B = 255 - t;
					break;
				};

	}; // case


	return (R << 16) | (G << 8) | B;
}

int mandelbrot_rainbow(t_env *e, int x, int y, int max_iterations)
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
	double c0x = 1.5 * (0 - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->offset_x;
	double c0y = (0 - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->offset_y;
	double d = mdist(cx, cy, max_iterations);
	double maxd = mdist(c0x, c0y, max_iterations);
	if (i >= max_iterations) // interior
		return (create_color(0, 0, 0));
	return (GiveRainbowColor(fabs(log(d * 10000000)/maxd))); // exterior
}

int mclosetime_bof61(double cx, double cy , int iter_max,  int bailout2)
{
	int j, cln = 0;
	double x = cx, y = cy, u, cld = 4;
	for (j = 0; j <= iter_max; j++)
	{
		u = x*x + y*y; 
		if (u > bailout2)
			return j;
		if (u < cld)
		{
			cld = u;
			cln = j;
		}
		u = x*x - y*y + cx;
		y = 2*x*y + cy;
		x = u;
	}
	return iter_max + cln % 15; //iterate, bof61

}

int mclosetime_bof60(double cx, double cy, int iter_max,  int bailout2)
{ int j;
  double x = cx, y = cy, u, cld = 4;
  for (j = 0; j <= iter_max; j++)
  { u = x*x + y*y; 
    if (u > bailout2) return j;
    if (u < cld) cld = u;  
    u = x*x - y*y + cx;
    y = 2*x*y + cy;
    x = u;
  }
 
  if (cld > 1) return iter_max+2;
  return iter_max + ((int)(500*cld) % 15);
}

int mandelbrot(t_env *e, int x, int y, int max_iterations)
{
	double cx = 1.5 * (x - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->offset_x - 0.5 + e->offset_zoom_x;
	double cy = (y - HEIGHT / 2) / (0.5 * e->zoom * HEIGHT) + e->offset_y + e->offset_zoom_y;
	int last_iter = mclosetime_bof60(cx, cy,max_iterations, 4.0);
	if (last_iter >= max_iterations)
		return (get_color_from_img(&e->pal, (last_iter - max_iterations) * 5.0, max_iterations));
	return (get_color_from_img(&e->pal, last_iter, max_iterations));
}

int julia(t_env *e, double x, double y, int max_iterations)
{
	double cx = -0.8 + e->mouse_x * 1.1;
	double cy = 0.3 - e->mouse_y * 0.32;
	double zx = 1.5 * (x - HALF_WIDTH) / (0.5 * e->zoom * WIDTH) + e->offset_x;
	double zy = (y - HALF_HEIGHT) / (0.5 * e->zoom * HEIGHT) + e->offset_y;
	double zxx = 0, zyy = 0;
	//double nu = 0.0;
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
		//nu += exp(-sqrt(zx*zx + zy*zy));
		i++;
	}
	if (i >= max_iterations)
		return 0;
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
