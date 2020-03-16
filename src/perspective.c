#include "head.h"

static double	get_max_z(t_fdf *fdf)
{
	double	mn;
	double	mx;
	int		i;
	int		j;

	mn = fdf->zarr[0][0];
	mx = fdf->zarr[0][0];
	i = 0;
	while (i < fdf->full->hei)
	{
		j = 0;
		while (j < fdf->full->wid)
		{
			mn = fdf->zarr[i][j] < mn ? fdf->zarr[i][j] : mn;
			mx = fdf->zarr[i][j] > mx ? fdf->zarr[i][j] : mx;
			j++;
		}
		i++;
	}
	fdf->z_max = mx;
	fdf->z_min = mn;
	mx = fabs(mx) / 3.0 * 2.0;
	mn = fabs(mn) / 3.0 * 2.0;
	return (mx > mn ? mx : mn);
}

void			normalize_z(t_fdf *fdf)
{
	int		i;
	int		j;
	double	zdivisor;

	zdivisor = get_max_z(fdf);
	if (!zdivisor)
		return ;
	i = 0;
	while (i < fdf->full->hei)
	{
		j = 0;
		while (j < fdf->full->wid)
		{
			fdf->zarr[i][j] /= zdivisor;
			j++;
		}
		i++;
	}
	fdf->z_max /= zdivisor;
	fdf->z_min /= zdivisor;
}

void			find_min_max(t_fdf *fdf)
{
	int			i;
	int			j;
	double		mn;
	double		mx;

	mn = fdf->map[0][0].y;
	mx = fdf->map[0][0].y;
	i = 0;
	while (i < fdf->full->hei)
	{
		j = 0;
		while (j < fdf->full->wid)
		{
			mn = fdf->map[i][j].y < mn ? fdf->map[i][j].y : mn;
			mx = fdf->map[i][j].y > mx ? fdf->map[i][j].y : mx;
			j++;
		}
		i++;
	}
	fdf->r = fabs(mn) > fabs(mx) ? fabs(mx) : fabs(mn);
}

void			matrix(t_3dmap *map, double r, double siz)
{
	if (r)
	{
		map->y = (map->y / r) + map->coef;
		map->x /= map->y;
		map->z /= map->y;
	}
	map->x *= siz;
	map->y *= siz;
	map->z *= siz;
}