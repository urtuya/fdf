#include "head.h"


void	set_offset(t_fdf *fdf)
{
	int sizx;
	int sizy;

	sizx = (HEI - 100) / fdf->hei;
	sizy = (WID - 100) / fdf->wid;
	fdf->siz = ft_min(sizx, sizy);
	fdf->offx = (HEI - (fdf->hei * fdf->siz - fdf->siz)) / 2;
	fdf->offy = (WID - (fdf->wid * fdf->siz - fdf->siz)) / 2;
}

void	draw_linex(t_fdf *fdf, t_coor cr1, int x, int y)
{
	t_coor cr2;

	cr2.x = x + fdf->siz;
	cr2.y = y;
	if (x < HEI - fdf->offx)
		draw_line(fdf, cr1, cr2);
}

void	draw_liney(t_fdf *fdf, t_coor cr1, int x, int y)
{
	t_coor cr2;

	cr2.x = x;
	cr2.y = y + fdf->siz;
	if (y < WID - fdf->offy)
		draw_line(fdf, cr1, cr2); // y
}

void	draw(t_fdf *fdf)
{
	t_coor cr1;
	int i;
	int j;
	int k;


	k = 0;
	i = fdf->offx;
	while (i <= HEI - fdf->offx)
	{
		j = fdf->offy;
		while (j <= WID - fdf->offy)
		{
			cr1.x = i;
			cr1.y = j;
			if (fdf->map[k].z)
				fdf->color = 0xFFFFFF;
			else 
				fdf->color = 0xEE82EE;
			draw_linex(fdf, cr1, i, j);
			draw_liney(fdf, cr1, i, j);
			j += fdf->siz;
			k++;
		}
		i += fdf->siz;
	}
}

void	isometric(t_3dmap *arr)
{
	double	prev_x;
	double	prev_y;

	prev_x = arr->x;
	prev_y = arr->y;

	arr->x = (prev_x - prev_y) * cos(0.523599);
	arr->y = -arr->z + (prev_x + prev_y) * sin(0.523599);
}


void	draw_isometric(t_fdf *fdf)
{
	int i;
	t_coor coor[fdf->map_len];

	i = 0;
	while (i < fdf->map_len)
	{
		isometric(&fdf->map[i]);
		printf("%d: x = %f y = %f z = %f\n", i, fdf->map[i].x, fdf->map[i].y, fdf->map[i].z);
		i++;
	}

	int j;
	t_coor cr1, cr2;
	int k = 0;
	i = fdf->offx;
	while (i <= HEI - fdf->offx)
	{
		j = fdf->offy;
		while (j <= WID - fdf->offy)
		{
			cr1.x = i;
			cr1.y = j;
			if (fdf->map[k].z)
				fdf->color = 0xFFFFFF;
			else 
				fdf->color = 0xEE82EE;
			cr2.x = fdf->map[k].x + fdf->siz + fdf->offx;
			cr2.y = fdf->map[k].y + fdf->offy;
			draw_line(fdf, cr1, cr2);
			// cr2.x = fdf->map[k].x + fdf->offx;
			// cr2.y = fdf->map[k].y + fdf->siz + fdf->offy;
			// draw_line(fdf, cr1, cr2);
			k++;
			j+= fdf->siz;
		}
		i += fdf->siz;
	}
}