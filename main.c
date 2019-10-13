#include "head.h"

void	check_malloc(void *addr)
{
	if (!addr)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	
}

int	deal_key()
{
	write(1, "key\n", 4);
	return (0);
}

int mouse()
{
	write(1, "mice\n", 5);
	return (0);
}
int wtf()
{
	write(1, "wtf\n", 4);
	return (0);
}

int	loop()
{
	write(1, "loop\n", 5);
	return (0);
}

void	fill_white(t_fdf *fdf, int height, int width)
{
	int x;
	int y;

	x = 0;
	fdf->color = 0xFFFFFF;
	while (x <= height)
	{
		draw_line_bresengham(fdf, 0, x, width, x);
		x++;
	}
}

t_fdf	*init_fdf(char *map)
{
	t_fdf	*fdf;
	int		fd;

	fdf = (t_fdf*)malloc(sizeof(t_fdf));
	fdf->wid = 0;
	fdf->hei = 0;
	fdf->color = 0xEE82EE;
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
	fill_3dmap(fdf); 
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 500, 500, "square");

	return (fdf);
}

int main(int argc, char **argv)
{
	t_fdf	*fdf;

	fdf = init_fdf(argv[1]);
	void	*img;
	char	*img_ptr;

	// fill_white(fdf, height, width);
	// fdf->color = 0xFFFFFF;
	// draw_line_wu(fdf, 100, 100, 101, 200);
	// draw_line_bresengham(fdf, 100, 100, 200, 200);
	
	// draw_line_bresengham(fdf, 200, 100, 200, 250);
// fdf->color = 0x07FFFF;
	// draw_line_bresengham(fdf, 200, 100, 300, 50);
	// draw_lines_between_coords(fdf);

	// img = mlx_new_image(fdf->mlx_ptr, 100, 1);
	// img->ptr = 	
	// mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, img_ptr, 100, 1);

	int i;
	int j;
	int offset = 0;
	printf("hei = %d\n",fdf->hei);
	printf("k = %d\n", fdf->map_len);
	i = 20;
	while (i <= fdf->hei * 20)
	{
		printf("x1 = %.f y1 = %.f\n", fdf->map[i].x, fdf->map[i].y);
		printf("x2 = %.f y2 = %.f\n", fdf->map[i + fdf->hei].x, fdf->map[i + fdf->hei].y);
		offset = 40;
		j = 20;
		while (j <= offset)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, i, j, fdf->color);
			j++;
		}
		i+=20;
	}


	j = 20;
	while (j <= fdf->wid * 20)
	{
		i = 20;
		while (i <= 40)
		{
			mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, i, j, fdf->color);
			i++;
		}
		j += 20;
	}



	mlx_loop(fdf->mlx_ptr);



	return (0);
}
