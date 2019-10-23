#include "head.h"

int		key_press(int keykode, t_fdf *fdf)
{
	if (keykode == 4)
		fdf->key.h_key = 0;
	if (keykode == 19)
	{
		// mlx_clear_window(fdf->full->mlx, fdf->full->win);
		// clean_main_map(fdf);
		// fdf->ang.a_x = 30;
		// draw2(fdf);
		fdf->key.proj = 1;
	}
	fdf->key.anykey_ispressed = fdf->key.h_key != 0 ? 1 : 0;
	return (0);
}

int		key_release(int keykode, t_fdf *fdf)
{
	t_proj	proj;

	if (keykode == 4)
	{
		fdf->key.h_key = 1;
	}
	if (keykode == 19)
	{
		fdf->key.proj = 1;
		fdf->proj = PARALLEL;
		fdf->ang.a_x = 120.0;
		fdf->ang.a_y = 0.0;
		fdf->ang.a_z = 0.0;
		clean_main_map(fdf);
		find_min_max(fdf);
		mlx_clear_window(fdf->full->mlx, fdf->full->win);
		draw(fdf, fdf->proj ? matrix : set_iso_coords);
	}
	fdf->key.anykey_ispressed = fdf->key.h_key != 0 ? 1 : 0;
	return (0);
}

int		mouse_press(int btn, int x, int y, t_fdf *fdf)
{
	t_proj		proj;

	if (x < 0 || x > HEI || y < 0 || y > WID)
		return (1);
	fdf->ang.a_x = 0.0;
	fdf->ang.a_y = 0.0;
	fdf->ang.a_z = 0.0;
	proj = fdf->key.proj == 1 ? PARALLEL : ISO;
	if (btn == 1)
		fdf->ms.left = 1;
	else if (fdf->key.h_key && (btn == 4 || btn == 5))
	{
		fdf->h_zarr *= btn == 4 ? 1.1 : 0.9;
		mlx_clear_window(fdf->full->mlx, fdf->full->win);
		draw(fdf, fdf->proj ? matrix : set_iso_coords);
	}
	else if (!fdf->key.anykey_ispressed && (btn == 4 || btn == 5))
	{
		fdf->siz *= btn == 4 ? 1.1 : 0.9;
		mlx_clear_window(fdf->full->mlx, fdf->full->win);
		draw(fdf, fdf->proj ? matrix : set_iso_coords);
	}
	return (0);
}

int		mouse_release(int btn, int x, int y, t_fdf *fdf)
{
	if (btn == 1)
		fdf->ms.left = 0;
	return (0);
}

int		mouse_move(int x, int y, t_fdf *fdf)
{
	int	prev_x;
	int	prev_y;
	t_proj proj;

	if (x < 0 || x > HEI || y < 0 || y > WID)
		return (1);
	proj = fdf->key.proj == 1 ? PARALLEL : ISO;
	prev_x = fdf->ms.x;
	prev_y = fdf->ms.y;
	fdf->ms.x = x;
	fdf->ms.y = y;
	if (fdf->ms.left == 1)
	{
		fdf->ang.a_y = (double)(y - prev_y) * 0.2;
		fdf->ang.a_x = (double)(x - prev_x) * 0.2;
		fdf->ang.a_z = (double)((x - prev_x) / 2 + (y - prev_y) / 2) * 0.2;
		mlx_clear_window(fdf->full->mlx, fdf->full->win);
		draw(fdf, proj ? matrix : set_iso_coords);
	}
	return (0);
}
