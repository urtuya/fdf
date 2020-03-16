#include "head.h"

static int	ipart(double x)
{
	return ((int)x);
}

static double fpart(double x)
{
	return (x - (int)x);
}

void		wu_draw_line(t_map *fdf, t_coor cr1, t_coor cr2, int color)
{
	t_line	ln;
	t_coor	tmp;
	double	gradient;

	double xgap;
	int xpx11;
	int ypx11;
	int xpx12;
	int ypx12;
	double intery;

	if (cr2.x  < cr1.x)
	{
		tmp = cr1;
		cr1 = cr2;
		cr2 = tmp;
	}
	ln.dx = cr2.x - cr1.x;
	ln.dy = cr2.y - cr1.y;
	gradient = ln.dy / (ln.dx ? ln.dx : 1);
	ln.xe = (int)(round(cr1.x));
	ln.ye = cr1.y  + gradient * (ln.xe - cr1.x);
	xgap = 1 - fpart(cr1.x + 0.5);
	xpx11 = (int)(ln.xe + fdf->offx);
	ypx11 = ipart(ln.ye) + (int)fdf->offy;
	if (!(xpx11 < 0 || ypx11 < 0 || xpx11 > HEI || ypx11 + 1 > WID))
	{
		pixel_put(fdf, xpx11, ypx11, (int)(color * (1 - fpart(ln.ye)) * xgap));
		pixel_put(fdf, xpx11, ypx11 + 1, (int)(color * fpart(ln.ye) * xgap));
	}
	intery = ln.ye + gradient;

	ln.xe = (int)(round(cr2.x));
	ln.ye = cr2.y + gradient * (ln.xe - cr2.x);
	xgap = fpart(cr2.x + 0.5);
	xpx12 = ln.xe + (int)fdf->offx;
	ypx12 = ipart(ln.ye) + (int)fdf->offy;
	if (!(xpx12 < 0 || ypx12 < 0  || xpx12 > HEI || ypx12 + 1 > WID))
	{
		pixel_put(fdf, xpx12, ypx12, (int)(color * (1 - fpart(ln.ye)) * xgap));
		pixel_put(fdf, xpx12, ypx12 + 1, (int)(color * fpart(ln.ye) * xgap));
	}
	ln.x = xpx11 + 1;
	while (ln.x < xpx12 - 1)
	{
		if (!(ln.x < 0 || ln.x > HEI || ipart(intery) + (int)fdf->offy < 0 || ipart(intery) + (int)fdf->offy > WID))
		{
			pixel_put(fdf, ln.x, ipart(intery) + (int)fdf->offy, (int)(1 - color * (1 - fpart(intery))));
			pixel_put(fdf, ln.x, ipart(intery) + 1 + (int)fdf->offy, (int)1 - (color * fpart(intery)));
		}
		intery += gradient;
		ln.x += 1;
	}
}