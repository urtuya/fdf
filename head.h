#ifndef HEAD_H
# define HEAD_H

# include <fcntl.h>
# include "libft/inc/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define HEI 1400
# define WID 1200

typedef enum	e_projection
{
	ISO,
	PARALLEL
}				t_proj;

typedef struct	s_mouse
{
	int	left;
	int	right;
	int	x;
	int y;
}				t_mouse;

typedef struct	s_key
{
	int	h_key;
	int	anykey_ispressed;
	int	proj;
	int	h_pressed;
}				t_key;

typedef struct	s_perspective
{
	double	fovy;
	double	near;
	double	far;
}				t_pers;

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
	double	coef;
}				t_3dmap;

typedef struct	s_angle
{
	double	a_x;
	double	a_y;
	double	a_z;
}				t_angle;

typedef struct	s_color
{
	int		start;
	int		end;
	int		curr;
}				t_color;

typedef struct	s_fdf
{
	t_map	*full;
	double	**zarr;
	t_3dmap	**map;
	t_angle	ang;
	t_mouse ms;
	t_key	key;
	t_proj	proj;
	t_color color;

	double	last_r;
	double	r;
	double	h_zarr;
	double	siz;
	int		offx;
	int		offy;
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
	int		xs;
	int		ys;
	int		xe;
	int		ye;
}				t_line;

//main.c
void			check_malloc(void	*data);

//init.c
void			init_zarr(t_fdf *fdf, int fd, char *filename);
void			read_map(t_fdf *fdf, int fd);
void			init_3dmap(t_fdf *fdf);

//draw.c
void			draw(t_fdf *fdf, void (*projection)(t_3dmap*, double, double));

//iso.c
void			set_iso_coords(t_3dmap *map, double h_zarr, double siz);
void			clean_main_map(t_fdf *fdf);


//hooks.c
int				mouse_move(int x, int y, t_fdf *fdf);
int				mouse_release(int btn, int x, int y, t_fdf *fdf);
int				mouse_press(int btn, int x, int y, t_fdf *fdf);
int				key_release(int keykode, t_fdf *fdf);
int				key_press(int keykode, t_fdf *fdf);

//perspective.c
void			matrix(t_3dmap *map, double r, double siz);

//rotaton.c
void			rotate(t_fdf *fdf);

#endif
