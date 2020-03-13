#include "head.h"

void	set_iso_coords(t_3dmap *map, double h_zarr, double siz)
{
	double	prev_x;
	double	prev_y;

	(void)h_zarr;
	prev_x = map->x;
	prev_y = map->y;
	map->x = ((prev_x - prev_y) * cos(0.523599)) * siz;
	map->y = (-map->z + (prev_x + prev_y) * sin(0.523599)) * siz;
}
