#include "head.h"

static double	get_coef(int hei, int wid)
{
	double	coef;

	coef = hei > wid ? hei / wid : wid / hei;
	if (coef < 2.1)
		coef = 3.1;
	else if (coef <= 5.1)
		coef = 5.1;
	return (coef);
}

void			init_3dmap(t_fdf *fdf)
{
	int		i;
	int		j;
	double	coef;

	coef = get_coef(fdf->full->hei, fdf->full->wid);
	check_malloc(fdf->map = (t_3dmap**)malloc(sizeof(t_3dmap*)\
												* fdf->full->hei));
	i = -1;
	while (++i < fdf->full->hei)
		check_malloc(fdf->map[i] = (t_3dmap*)malloc(sizeof(t_3dmap)\
												* fdf->full->wid));
	i = -1;
	while (++i < fdf->full->hei)
	{
		j = -1;
		while (++j < fdf->full->wid)
		{
			fdf->map[i][j].x = (double)(j - fdf->full->y_err);
			fdf->map[i][j].y = (double)(i - fdf->full->x_err);
			fdf->map[i][j].z = fdf->zarr[i][j] * fdf->h_zarr;
			fdf->map[i][j].coef = coef;
		}
	}
}

void			init_zarr(t_fdf *fdf, int fd, char *filename)
{
	char	*line;
	int		i;
	int		j;
	char	**tmp;

	if ((fd = open(filename, O_RDONLY)) < 0)
		print_error("Invalid file");
	check_malloc(fdf->zarr = (double**)malloc(sizeof(double*)\
					* fdf->full->hei));
	i = -1;
	while (++i < fdf->full->hei)
	{
		if (get_next_line(fd, &line) < 0)
			print_error("Error reading map");
		check_malloc(tmp = ft_strsplit(line, ' '));
		check_malloc(fdf->zarr[i] = (double*)malloc(sizeof(double)\
					* fdf->full->wid));
		j = -1;
		while (++j < fdf->full->wid)
			fdf->zarr[i][j] = ft_atoi(tmp[j]);
		ft_strdel(&line);
		ft_freesplit(tmp);
	}
}

static void	set_off(t_fdf *fdf)
{
	double	a;
	double	b;

	fdf->h_zarr = 1.0;
	fdf->siz = 1.0;
	fdf->full->offx = HEI / 2;
	fdf->full->offy = WID / 2;
	a = WID / fdf->full->wid / 2;
	b = HEI / fdf->full->hei / 2;
	fdf->siz = a < b ? a : b;
	fdf->siz = !fdf->siz ? 1 : fdf->siz;
	fdf->prev_siz = fdf->siz;
	fdf->ang.a_x = 0.0;
	fdf->ang.a_y = 0.0;
	fdf->ang.a_z = 0.0;
	fdf->full->x_err = fdf->full->hei / 2;
	fdf->full->y_err = fdf->full->wid / 2;
	fdf->color = 0x9933FF;
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
		print_error("Error open file");
	read_map(fdf, fd);
	init_zarr(fdf, fd, filename);
	normalize_z(fdf);
	set_off(fdf);
	init_3dmap(fdf);
	fdf->ms = (t_mouse){0,0,0};
	fdf->full->mlx = mlx_init();
	fdf->full->win = mlx_new_window(fdf->full->mlx, HEI, WID, "FdF");
	return (fdf);
}