#include "head.h"

void		check_malloc(void	*data)
{
	if (!data)
	{
		fprintf(stderr, "malloc error\n");
		exit (1);
	}
}

//void		init_mouse(t_mouse *ms, t_map *map)
void		init_mouse_keys(t_fdf *fdf)
{
	fdf->ms.left = 0;
	fdf->ms.x = 0;
	fdf->ms.y = 0;
	fdf->key.h_key = 0;
	fdf->key.anykey_ispressed = 0;
}

static void	set_off(t_fdf *fdf)
{
	double	a;
	double	b;

	fdf->h_zarr = 1.0;
	fdf->siz = 0;
	fdf->full->offx = HEI / 2;
	fdf->full->offy = WID / 2;
	a = WID / fdf->full->wid / 2;
	b = HEI / fdf->full->hei / 2;
	fdf->siz = a < b ? a : b; 
	fdf->ang.a_x = 0.0;
	fdf->ang.a_y = 0.0;
	fdf->ang.a_z = 0.0;
	fdf->full->x_err = fdf->full->hei / 2;
	fdf->full->y_err = fdf->full->wid / 2;
}

t_fdf		*init_fdf(char *filename)
{
	t_fdf	*fdf;
	int		fd;

	check_malloc(fdf = (t_fdf*)malloc(sizeof(t_fdf)));
	check_malloc(fdf->full = (t_map*)malloc(sizeof(t_map)));
	fdf->full->wid = 0;
	fdf->full->hei = 0;
	fdf->zarr = NULL;
	fdf->map = NULL;
	if ((fd = open(filename, O_RDONLY)) < 0)
		exit (1);
	read_map(fdf, fd);
	init_zarr(fdf, fd, filename);
	set_off(fdf);
	init_cam(fdf);
	init_3dmap(fdf);
	init_mouse_keys(fdf);
	//init_mouse(&fdf->ms, fdf->full);
	fdf->full->mlx = mlx_init();
	fdf->full->win = mlx_new_window(fdf->full->mlx, HEI, WID, "1000x1000");
	return (fdf);
}

void		apply_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->full->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->full->win, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->full->win, 6, 0, mouse_move, fdf);
	mlx_hook(fdf->full->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->full->win, 3, 0, key_release, fdf);
}

int			main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "usage\n");
		exit(1);
	}
	fdf = init_fdf(argv[1]);
	fdf->flag = 0;
	draw(fdf, ISO);
	// ultra_draw(fdf); //this hleb
	apply_hooks(fdf);
	mlx_loop(fdf->full->mlx);
	return (0);
}