#include <fcntl.h>
#include "libft/inc/libft.h"
#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

# define HEI 1000
# define WID 1000

typedef struct	s_mouse
{
	int	left;
	int	x;
	int y;
}				t_mouse;

typedef struct	s_key
{
	int	h_release;
}				t_key;

typedef struct	s_coordinates
{
	int	x;
	int	y;
}				t_coor;

typedef struct	s_map
{
	int		hei;
	int		wid;
	void	*win;
	void	*mlx;
	int		map_len;
	double	offx;
	double	offy;
	int		x_err;
	int		y_err;
	
}				t_map;

typedef struct	s_3dmap
{
	double	x;
	double	y;
	double	z;
	int		color;

}				t_3dmap;

typedef struct	s_angle
{
	double	a_x;
	double	a_y;
	double	a_z;
}				t_angle;

typedef struct	s_fdf
{
	t_map	*full;
	double	**zarr;
	t_3dmap	**map;
	t_angle	ang;
	t_mouse ms;
	t_key	key;

	double	h_zarr;
	double	siz;
	int		offx;
	int		offy;
	int		flag;
}				t_fdf;

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		err;
	int		x;
	int		y;
	int		sy;
	int		sx;
}				t_line;

//main.c
void	check_malloc(void	*data);

//init.c
void	init_zarr(t_fdf *fdf, int fd, char *filename);
void	read_map(t_fdf *fdf, int fd);
void    init_3dmap(t_fdf *fdf);

//draw.c
void	draw(t_fdf *fdf);

//iso.c
void    iso_coords(t_fdf *fdf);

//hooks.c
int     mouse_move(int x, int y, t_fdf *fdf);
int     mouse_release(int btn, int x, int y, t_fdf *fdf);
int     mouse_press(int btn, int x, int y, t_fdf *fdf);
int     key_release(int keykode, t_fdf *fdf);

//rotation.c
void    rotation(t_3dmap *map, t_fdf *fdf);