#include <stdio.h>
#include "mlx.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/inc/libft.h"

# define WID 1000
# define HEI 1000
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
	int		dx;
	int		dy;
	int		err;
	int		x;
	int		y;
	int		sx;
	int		sy;
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
	double		siz;
	int		color;
	t_coor	coor;

	int		hei;
	int		wid;
	double	x_err;
	double	y_err;

	int		offx;
	int		offy;

	double	angle;
	double	h_zarr;
	double	**zarr;
	int		map_len;
	t_3dmap	**map;
}				t_fdf;


