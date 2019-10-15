#include "head.h"

static void set_coords(t_3dmap *map, t_fdf *fdf, int axis)
{
    double  prev_x;
    double  prev_y;
    double  prev_z;

    prev_x = map->x;
    prev_y = map->y;
    prev_z = map->z;
    if (axis == 1)
    {
        map->y = prev_y * cos(fdf->angle) + prev_z * sin(fdf->anlge);
        
    }
}

void           rotation(t_fdf *fdf)
{
    int i;
    int j;

    i = 0;
    while (i < fdf->hei)
    {
        j = 0;
        while (j < fdf->wid)
        {
            set_coords(&fdf->map[i][j], fdf, 1);
            j++;
        }
        i++;
    }
}