#include "head.h"

void	init_cam(t_fdf *fdf)
{
	fdf->cam.x = 0.0;
	fdf->cam.y = 0.0;
}

void	matrix(t_3dmap *map, double r, double siz)
{
	double	zdivisor;

	zdivisor = (r * map->y + 1) + 0.001;
	map->x = map->x / zdivisor * siz;
	map->y = map->y / zdivisor * siz;
	map->z = map->z / zdivisor * siz;	

	printf("x = %f y = %f z = %f\n", map->x, map->y, map->z);
}

void	get_coor_for_pers(t_fdf *fdf)
{
	int i;
	int j;
	double ydivisor;

	i = 0;
	fdf->cam.y = 10.0;
	while (i < fdf->full->hei)
	{
		j = 0;
		while (j < fdf->full->wid)
		{
			ydivisor = 2;
			fdf->map[i][j].y = -fdf->zarr[i][j] * fdf->h_zarr * fdf->siz / ydivisor;
			fdf->map[i][j].x = (double)(j - fdf->full->y_err) * fdf->siz / ydivisor;
			fdf->map[i][j].z = 0.0;
			j++;
		}
		i++;
	}
}


void	ultra_draw(t_fdf *fdf)
{
	int		i;
	int		j;
	t_3dmap	now;
	t_3dmap	next;

	get_coor_for_pers(fdf);
	i = 0;
	while (i < fdf->full->hei)
	{
		j = 0;
		while (j < fdf->full->wid)
		{
			if (i < fdf->full->hei - 1)
			{
				draw_lines(fdf, fdf->map[i][j], fdf->map[i + 1][j]);
			}
			if (j < fdf->full->wid - 1)
			{
				draw_lines(fdf, fdf->map[i][j], fdf->map[i][j + 1]);
			}
			j++;
		}
		i++;
	}
	
}