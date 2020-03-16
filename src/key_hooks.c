#include "head.h"

static int		key_press_clicks(int code)
{
	if (code == CLOSE_IMAGE || code == ISOMETRIC || code == PARAL
		|| code == HEIGHT_UP || code == HEIGHT_DOWN ||
		code == CHANGE_COLOR || code == DEFAULT_COLOR)
		return (1);
	return (0);
}

static void		parallel_projection(t_fdf *fdf)
{
	fdf->proj = PARALLEL;
	fdf->siz = fdf->prev_siz * 2.1;
	fdf->ang.a_x = 120.0;
	fdf->h_zarr = 1.0;
	clean_main_map(fdf);
	find_min_max(fdf);
}

static void		drawing_height(int keykode, t_fdf *fdf)
{
	fdf->ang.a_x = fdf->proj ? 120.0 : 0.0;
	fdf->h_zarr *= keykode == HEIGHT_UP ? 1.1 : 0.9;

	//--------------------DO NOT DELETE

	// if (fdf->h_zarr > 7.0 && fdf->proj == ISO)
	// 	fdf->h_zarr = 7.0;
	// else if (fdf->h_zarr > 5.0 && fdf->proj == PARALLEL)
	// 	fdf->h_zarr = 5.0;
	clean_main_map(fdf);
}

static void		color_rendering(int keykode, t_fdf *fdf)
{
	char	colors[12];

	fdf->ang.a_x = 0.0;
	if (keykode == DEFAULT_COLOR)
		fdf->color = (t_color){0x9933FF, 0x9933FF};
}


int				key_press(int keykode, t_fdf *fdf)
{
	if (!key_press_clicks(keykode))
		return (0);
	if (keykode == CLOSE_IMAGE)
		exit(0);
	fdf->ang.a_y = 0.0;
	fdf->ang.a_z = 0.0;
	if (keykode == PARAL)
		parallel_projection(fdf);
	else if (keykode == ISOMETRIC)
	{
		fdf->proj = ISO;
		fdf->siz = fdf->prev_siz;
		fdf->ang.a_x = 0.0;
		clean_main_map(fdf);
	}
	else if ((keykode == HEIGHT_UP || keykode == HEIGHT_DOWN))
		drawing_height(keykode, fdf);
	if (keykode == CHANGE_COLOR || keykode == DEFAULT_COLOR)
		color_rendering(keykode, fdf);
	ft_bzero(fdf->full->data_addr, HEI * WID * fdf->full->bpp / 8);
	draw(fdf, fdf->proj ? matrix : set_iso_coords);
	print_help(fdf->full);
	return (0);
}

