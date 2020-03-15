#include "head.h"

void	pixel_put(t_map *full, int x, int y, int color)
{
    int i;

    i = (x * full->bpp / 8) + (y * full->size_line);
    full->data_addr[i] = color;
    full->data_addr[++i] = color >> 8;
    full->data_addr[++i] = color >> 16;
	full->data_addr[++i] = 0;
}


void		draw_line(t_map *fdf, t_coor cr1, t_coor cr2, int color)
{
	t_line	ln;
	int		err1;
	int		err2;

	ln.dx = abs(cr1.x - cr2.x);
	ln.dy = abs(cr1.y - cr2.y);
	ln.sx = cr1.x < cr2.x ? 1 : -1;
	ln.sy = cr1.y < cr2.y ? 1 : -1;
	err1 = ln.dx - ln.dy;
	ln.x = cr1.x;
	ln.y = cr1.y;
	while (ln.x != cr2.x || ln.y != cr2.y)
	{
		if (!(ln.x + fdf->offx < 0 || ln.x + fdf->offx > HEI || ln.y + fdf->offy < 0 || ln.y + fdf->offy > WID))
		{
			pixel_put(fdf, ln.x + (int)fdf->offx, ln.y + (int)fdf->offy, color);
		}
		err2 = err1 * 2;
		if (err2 > -ln.dy)
		{
			err1 -= ln.dy;
			ln.x += ln.sx;
		}
		if (err2 < ln.dx)
		{
			err1 += ln.dx;
			ln.y += ln.sy;
		}
	}
}