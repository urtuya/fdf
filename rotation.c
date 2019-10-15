#include "head.h"

// static void set_coords(t_3dmap *map, t_fdf *fdf, double angle, int axis)
// {
//     double  prev_x;
//     double  prev_y;
//     double  prev_z;

//     prev_x = map->x;
//     prev_y = map->y;
//     prev_z = map->z;
//     if (axis == 1)
//     {
//         // fdf->angle = 30 / 180 * M_PI;
//         map->y = (prev_y * cos(fdf->angle) + prev_z * sin(fdf->angle)) * fdf->siz;
//         map->z = (-prev_y * sin(fdf->angle) + prev_z * cos(fdf->angle)) * fdf->siz;
//     }
//     else if (axis == 2)
//     {
//         // fdf->angle = 1 / 2 * M_PI;
//         map->x = (prev_x * cos(fdf->angle) + prev_z * sin(fdf->angle)) * fdf->siz;
//         map->z = (-prev_x * sin(fdf->angle) + prev_z * cos(fdf->angle)) * fdf->siz;
//     }
//     else if (axis == 3)
//     {
//         // fdf->angle = 2 / 3 * M_PI;
//         map->x = (prev_x * cos(fdf->angle) - prev_y * sin(fdf->angle)) * fdf->siz;
//         map->y = (-prev_x * sin(fdf->angle) + prev_y * cos(fdf->angle)) * fdf->siz;
//     }
// }

