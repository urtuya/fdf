#include "head.h"

void	check_valid(t_fdf *fdf, char *line)
{
	int i;
	int	wid_count;
	char	**tmp;
	int		j;

	if (!line)
	{
		fprintf(stderr, "there !line\n");
		exit(1);
	}
	check_malloc(tmp = ft_strsplit(line, ' '));
	// printf("line = %s\n", line);
	// printf("tmp[0] = %s\n", tmp[0]);
	i = 0;
	// printf("herefd\n");
	// exit(0);
	while (tmp[i])
		i++;
	if (!fdf->wid)
		fdf->wid = i;
	else if (fdf->wid != i)
	{
		printf("wid = %d i = %d\n", fdf->wid, i);
		fprintf(stderr, "invalid map\n");
		exit(1);
	}
	// printf("yeah\n");
}

void	read_map(t_fdf *fdf, int fd)
{
	char	*line;
	int		hei_count;

	// printf("here\n");
	hei_count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		check_valid(fdf, line);
		hei_count++;
	}
	fdf->hei = hei_count;
	close(fd);
	// set_map(fdf);
}

void	fill_zarr(t_fdf *fdf, int fd)
{
	int	i;
	int	j;
	int k;
	char *line;
	char **tmp;

	fdf->zarr = (double**)malloc(sizeof(double*) * fdf->hei);
	i = 0;
	// printf("heis = %d\n", fdf->hei);
	while (i < fdf->hei)
	{
		if (get_next_line(fd, &line) < 0)
		{
			fprintf(stderr, "ggnl error\n");
			exit(1);
		}
		tmp = ft_strsplit(line, ' ');
		fdf->zarr[i] = (double*)malloc(sizeof(double) * fdf->wid);
		j = 0;
		k = fdf->wid - 1;
		while (j < fdf->wid)
		{
			fdf->zarr[i][j] = (double)ft_atoi(tmp[k]);
			k--;
			j++;
		}
		ft_freesplit(tmp);
		i++;
	}
}

void	fill_3dmap(t_fdf *fdf)
{
	int		i;
	int		j;

	fdf->map = (t_3dmap**)malloc(sizeof(t_3dmap*) * (fdf->hei));
	i = 0;
	while (i < fdf->hei)
	{
		fdf->map[i] = (t_3dmap*)malloc(sizeof(t_3dmap) * (fdf->wid));
		i++;
	}
	i = 0;
	while (i < fdf->hei)
	{
		j = 0;
		while (j < fdf->wid)
		{
			fdf->map[i][j].x = (double)i - fdf->x_err;
			fdf->map[i][j].y = (double)j - fdf->y_err;
			fdf->map[i][j].z = fdf->zarr[i][j] * fdf->h_zarr;
			j++;
		}
		i++;
	}
}