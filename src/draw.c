#include "head.h"

static void		draw_lines(t_fdf *fdf, t_3dmap map1, t_3dmap map2)
{
	t_coor	cr1;
	t_coor	cr2;
	t_color color;
	int		red;
	int		green;
	int		blue;
	double	percentage;

	color = fdf->color;
	cr1.x = (int)map1.x;
	cr1.y = fdf->proj == PARALLEL ? (int)map1.z : (int)map1.y;
	percentage = percent(fdf->z_min, fdf->z_max, map1.static_z);
	// cr1.color = (int)((color.end - color.start) * percentage + color.start);
	// cr1.color = get_light(color.start, color.end, percentage);
	red = get_light((color.start >> 16) & 0xFF, (color.end >> 16) & 0xFF, percentage);
	green = get_light((color.start >> 8) & 0xFF, (color.end >> 8) & 0xFF, percentage);
	blue = get_light(color.start & 0xFF, color.end & 0xFF, percentage);
	cr1.color = (red << 16) | (green << 8) | blue;
	cr2.x = (int)map2.x;
	cr2.y = fdf->proj == PARALLEL ? (int)map2.z : (int)map2.y;
	percentage = percent(fdf->z_min, fdf->z_max, map2.static_z);
	// cr2.color = (int)((color.end - color.start) * percentage + color.start);
	// cr2.color = get_light(color.start, color.end, percentage);
	red = get_light((color.start >> 16) & 0xFF, (color.end >> 16) & 0xFF, percentage);
	green = get_light((color.start >> 8) & 0xFF, (color.end >> 8) & 0xFF, percentage);
	blue = get_light(color.start & 0xFF, color.end & 0xFF, percentage);
	cr2.color = (red << 16) | (green << 8) | blue;
	bresengham_draw_line(fdf->full, cr1, cr2);
	// wu_draw_line(fdf->full, cr1, cr2, color);
}

void			draw(t_fdf *fdf, void (*projection)(t_3dmap*, double, double))
{
	int		i;
	int		j;
	t_3dmap	now;
	t_3dmap	next;

	rotate(fdf);
	i = -1;
	while (++i < fdf->full->hei)
	{
		j = -1;
		while (++j < fdf->full->wid)
		{
			now = fdf->map[i][j];
			projection(&now, fdf->r, fdf->siz);
			if (j < fdf->full->wid - 1)
			{
				next = fdf->map[i][j + 1];
				projection(&next, fdf->r, fdf->siz);
				draw_lines(fdf, now, next);
			}
			if (i < fdf->full->hei - 1)
			{
				next = fdf->map[i + 1][j];
				projection(&next, fdf->r, fdf->siz);
				draw_lines(fdf, now, next);
			}
		}
	}
	mlx_put_image_to_window(fdf->full->mlx, fdf->full->win, fdf->full->map, 0, 0);
	print_help(fdf->full);
}
