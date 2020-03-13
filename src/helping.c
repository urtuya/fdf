#include "head.h"

static void		check_valid(t_fdf *fdf, char *line)
{
	int		i;
	char	**tmp;

	if (!line || !*line)
		print_error("Error while reading map");
	check_malloc(tmp = ft_strsplit(line, ' '));
	i = 0;
	while (tmp[i])
		i++;
	if (!fdf->full->wid)
		fdf->full->wid = i;
	else if (fdf->full->wid != i)
		print_error("map error");
	ft_freesplit(tmp);
}

void			read_map(t_fdf *fdf, int fd)
{
	char	*line;
	int		hei_count;
	int		gnl;

	hei_count = 0;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		check_valid(fdf, line);
		ft_strdel(&line);
		hei_count++;
	}
	fdf->full->hei = hei_count;
	close(fd);
	if (fdf->full->hei < 2 && fdf->full->wid < 2)
		print_error("Invalid map");
}

void	clean_main_map(t_fdf *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->full->hei)
	{
		j = 0;
		while (j < fdf->full->wid)
		{
			fdf->map[i][j].x = (double)(j - fdf->full->y_err);
			fdf->map[i][j].y = (double)(i - fdf->full->x_err);
			fdf->map[i][j].z = fdf->zarr[i][j] * fdf->h_zarr;
			j++;
		}
		i++;
	}
}
