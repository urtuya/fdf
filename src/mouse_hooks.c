#include "head.h"

int		mouse_press(int btn, int x, int y, t_fdf *fdf)
{
	if (x < 0 || x > HEI || y < 0 || y > WID)
		return (1);
	fdf->ang.a_x = 0.0;
	fdf->ang.a_y = 0.0;
	fdf->ang.a_z = 0.0;
	if (btn == MOUSE_LEFT_CLICK)
		fdf->ms.left = MOUSE_LEFT_CLICK;
	else if ((btn == SCROLL_UP || btn == SCROLL_DOWN))
	{
		fdf->siz *= btn == 4 ? 1.1 : 0.9;
		mlx_clear_window(fdf->full->mlx, fdf->full->win);
		draw(fdf, fdf->proj ? matrix : set_iso_coords);
		print_help(fdf->full);
	}
	return (0);
}

int		mouse_release(int btn, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (btn == 1)
		fdf->ms.left = 0;
	return (0);
}

int		mouse_move(int x, int y, t_fdf *fdf)
{
	int	prev_x;
	int	prev_y;

	if (x < 0 || x > HEI || y < 0 || y > WID)
		return (1);
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
		draw(fdf, fdf->proj ? matrix : set_iso_coords);
		print_help(fdf->full);
	}
	return (0);
}
