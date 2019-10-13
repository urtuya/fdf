#include <stdio.h>
#include "mlx.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/inc/libft.h"

typedef	enum	e_projection
{
	iso,
	parallel,
	conic
}				t_proj;

typedef struct	s_coordinates
{
	int		x;
	int		y;
	int		z;
}				t_coor;

typedef struct	s_line
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		sy;
	int		sx;
	int		dx;
	int		dy;
	float	err;
	int		x;
	int		y;
	int		diry;
}				t_line;

typedef struct	s_3dmap
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_3dmap;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;
	t_coor	coor;

	int		hei;
	int		wid;
	int		fd;

	double	**zarr;
	int		map_len;
	t_3dmap	*map;
}				t_fdf;


