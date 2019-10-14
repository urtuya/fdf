#include "head.h"


// --------------------- bresengham
// void	draw_line_bresengham(t_fdf *fdf, int x0, int y0, int x1, int y1)
// {
// 	int		err;
// 	int		dx;
// 	int		dy;
// 	float	derr;
// 	int		x;
// 	int		y;
// 	int		y_step	;
// 	int steep;

// 	steep = (abs(y1 - y0)) < (abs(x1 - x0));
// 	printf("steep = %d\n", steep);
// 	if (steep)
// 	{
// 		ft_swap(x0, y0);
// 		ft_swap(x1, y1);
// 	}
// 	printf("x0 = %d x1 = %d\n", x0, x1);
// 	if (x0 > x1)
// 	{
// 		printf("here\n");
// 		ft_swap(x0, x1);
// 		ft_swap(y0, y1);
// 	}
// 	dx = x1 - x0;
// 	dy = abs(y1 - y0);
// 	err = dx / 2;
// 	derr = dy;

// 	y_step = (y0 < y1) ? 1 : -1;
// 	x = x0;
// 	y = y0;
// 	while (x <= x1)
// 	{
// 		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, steep ? y : x,steep ? x : y, fdf->color);
// 		err = err - dy;
// 		if (err < 0)
// 		{
// 			y = y + y_step;
// 			err = err + dx;
// 		}
// 		x++;
// 	}

// }

// void	draw_pixel(t_fdf *fdf, int x, int y, float bright)
// {
// 	mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, fdf->color * (1 - bright));
// }


// float fPartOfNumber(float x) 
// { 
//     if (x >= 0.0)
// 		return (x - (int)x);
//     else
// 		return (x - ((int)x + 1)); 
// }

// // -----------------------------xiaolin wu
// void	draw_line_wu(t_fdf *fdf, int x0, int y0, int x1, int y1)
// {
// 	int		steep;
// 	float	dx;
// 	float	dy;
// 	float	gradient;
// 	float	intersect_y;

// 	int		xpxl1;
// 	int		xpxl2;
// 	int		x;

// 	int abs1, abs2;

// 	steep = (abs1 = abs(y1 - y0)) > (abs2 = abs(x1 - x0));
// 	if (steep)
// 	{
// 		ft_swap(x0, y0);
// 		ft_swap(x1, y1);
// 	}
// 	if (x0 >= x1)
// 	{
// 		ft_swap(x0, x1);
// 		ft_swap(y0, y1);
// 	}
// 	dx = x1 - x0;
// 	dy = y1 - y0;
// 	gradient = dy / dx;
// 	if (dx == 0.0)
// 		gradient = 1.0;
// 	xpxl1 = x0;
// 	xpxl2 = x1;
// 	intersect_y = y0;
// 	x = xpxl1;
// 	while (x <= xpxl2)
// 	{
// 		draw_pixel(fdf, steep ? (int)intersect_y : x, steep ? x : (int)intersect_y, 1 - fPartOfNumber(intersect_y));
// 		draw_pixel(fdf, steep ? (int)intersect_y - 1 : x, steep ? x : (int)intersect_y - 1, fPartOfNumber(intersect_y));
// 		intersect_y += gradient;
// 		x++;
// 	}
// }



void	draw_line(t_fdf *fdf, t_coor cr1, t_coor cr2)
{
	t_line	ln;
	int		e2;

	if (cr1.x > cr2.x || cr1.y > cr2.y)
	{
		ft_swap(&cr1.x, &cr2.x);
		ft_swap(&cr1.y, &cr2.y);
	}
	ln.dx = abs(cr2.x - cr1.x);
	ln.sx = cr1.x < cr2.x ? 1 : -1;
	ln.dy = -abs(cr2.y - cr1.y);
	ln.sy = cr1.y < cr2.y ? 1 : -1;
	ln.err = ln.dx + ln.dy;
	ln.x = cr1.x;
	ln.y = cr1.y;
	while (ln.x <= cr2.x && ln.y <= cr2.y)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, ln.y, ln.x, fdf->color);
		e2 = 2 * ln.err;
		if (e2 >= ln.dy)
		{
			ln.err += ln.dy;
			ln.x += ln.sx;
		}
		if (e2 <= ln.dx)
		{
			ln.err += ln.dx;
			ln.y += ln.sy;
		}
	}
}