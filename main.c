#include "head.h"

void	check_malloc(void *addr)
{
	if (!addr)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	
}

t_fdf	*init_fdf(char *map)
{
	t_fdf	*fdf;
	int		fd;

	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	fdf->wid = 0;
	fdf->h_zarr = 1.0;
	fdf->hei = 0;
	fdf->color = 0xEE82EE;
	fdf->siz = 5;
	if ((fd = open(map, O_RDONLY)) < 0)
	{
		fprintf(stderr, "fd error\n");
		exit(1);
	}
	read_map(fdf, fd);
	if ((fd = open(map, O_RDONLY)) < 0)
	{
		fprintf(stderr, "fd error\n");
		exit(1);
	}
	fill_zarr(fdf, fd);
	set_offset(fdf);
	fill_3dmap(fdf);

	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, HEI, WID, "square 1000x1000");

	return (fdf);
}

int	mouse(int button, int x, int y, t_fdf *fdf)
{
	printf("MOUSE_%d: %d %d\n",button, x, y);
	if (button == 4)
		fdf->siz -= 0.0001;
	if (button == 5)
		fdf->siz += 0.0001;
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	// fill_3dmap(fdf);
	draw_rot(fdf, fdf->map);
	printf("siz = %f\n", fdf->siz);
	
	return (0);
}

int mouse_press(int button, int x, int y, t_fdf *fdf)
{
	// if (button == 4)
	// 	fdf->siz
	return (0);
}
int	key_press(int keykode, t_fdf *fdf)
{
	if (keykode == 12)
	{
		mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
		draw_parallel(fdf);
	}
	return (0);
}

int	mouse_release(int button, int x, int y, t_fdf *fdf)
{
	// if (button == 1)
	// {
	// 	printf("MOUSE_%d: %d:%d\n", button, x,y);
	// 	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	// 	draw_rot(fdf, fdf->map, x, y);
	// }
	return (0);
}

int main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = init_fdf(argv[1]);

	draw_iso(fdf, fdf->map);

	// mlx_mouse_hook(fdf->win_ptr, mouse, fdf);
	mlx_hook(fdf->win_ptr, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win_ptr, 2, 0, key_press, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
