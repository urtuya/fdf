#include "head.h"

void	set_iso_coords(t_3dmap *map, double siz)
{
	double	prev_x;
	double	prev_y;

	prev_x = map->x;
	prev_y = map->y;
	map->x = ((prev_x - prev_y) * cos(0.523599)) * siz;
	map->y = (-map->z + (prev_x + prev_y) * sin(0.523599)) * siz;
}
void        rotate(t_fdf *fdf)
{
    int     i;
    int     j;

    i = 0;
    while (i < fdf->full->hei)
    {
        j = 0;
        while (j < fdf->full->wid)
        {
            rot_y(&fdf->map[i][j], fdf->ang.a_y);
            rot_x(&fdf->map[i][j], fdf->ang.a_x);
            rot_z(&fdf->map[i][j], fdf->ang.a_z);
            j++;
        }
        i++;
    }
    fdf->flag = 1;
}