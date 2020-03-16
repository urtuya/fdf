#ifndef HEAD_H
# define HEAD_H

# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>

# ifdef __APPLE__
#  define HEI 1400
#  define WID 1200
#  define KEY_PRESS 0
#  define MOUSE_PRESS 0
#  define MOUSE_MOVE 0
#  define MOUSE_RELEASE 0
#  define CLOSE_IMAGE 53
#  define ISOMETRIC 18
#  define PARAL 19
#  define HEIGHT_UP 24
#  define HEIGHT_DOWN 27
#  define CHANGE_COLOR 20
#  define DEFAULT_COLOR 6
# elif __linux__
#  define HEI 900
#  define WID 600
#  define KEY_PRESS 1L
#  define MOUSE_PRESS 4L
#  define MOUSE_MOVE 64L
#  define MOUSE_RELEASE 8L
#  define CLOSE_IMAGE 65307
#  define ISOMETRIC 49
#  define PARAL 50
#  define HEIGHT_UP 61
#  define HEIGHT_DOWN 45
#  define CHANGE_COLOR 51
#  define DEFAULT_COLOR 122
# endif

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define MOUSE_LEFT_CLICK 1

typedef enum	e_projection
{
	ISO,
	PARALLEL
}				t_proj;

typedef struct	s_mouse
{
	int	left;
	int	x;
	int y;
}				t_mouse;

typedef	struct	s_color
{
	int start;
	int end;
}				t_color;

typedef struct	s_coordinates
{
	int		x;
	int		y;
	int		z;
	int		color;
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



	int		*map;
	char	*data_addr;
	int		bpp;
	int		size_line;
	int		endian;
}				t_map;

typedef struct	s_3dmap
{
	double	x;
	double	y;
	double	z;
	double	coef;
	double	static_z;
}				t_3dmap;

typedef struct	s_angle
{
	double	a_x;
	double	a_y;
	double	a_z;
}				t_angle;

// typedef struct	s_color
// {
// 	int start;
// 	int curr;
// 	int end;
// }				t_color;

typedef struct	s_fdf
{
	t_map	*full;
	double	**zarr;
	t_3dmap	**map;
	t_angle	ang;
	t_mouse ms;
	t_proj	proj;
	t_color color;

	double	z_max;
	double	z_min;

	double	r;
	double	h_zarr;
	double	prev_siz;
	double	siz;
	int		offx;
	int		offy;

}				t_fdf;

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		x;
	int		y;
	int		sy;
	int		sx;
	int		color;

	int		xe;
	int		ye;
}				t_line;



//-----------------------draw.c
void			draw(t_fdf *fdf, void (*projection)(t_3dmap*, double, double));
void			bresengham_draw_line(t_map *fdf, t_coor cr1, t_coor cr2);

//-----------------------perspective.c
void			normalize_z(t_fdf *fdf);
void			matrix(t_3dmap *map, double r, double siz);
void			find_min_max(t_fdf *fdf);


//-----------------------init.c
t_fdf			*init_fdf(int ac, char **av);
void			init_zarr(t_fdf *fdf, int fd, char *filename);
void			init_3dmap(t_fdf *fdf);


//-----------------------error.c
void			check_malloc(void	*data);
void			print_error(char *str);
void			print_help(t_map *map);


//-----------------------rotation.c
void			rotate(t_fdf *fdf);

//-----------------------helping.c
void			clean_main_map(t_fdf *fdf);
void			read_map(t_fdf *fdf, int fd);

//------------------------iso.c
void			set_iso_coords(t_3dmap *map, double h_zarr, double siz);

//------------------------hooks (key_hooks.c mouse_hooks.c)
int				key_press(int keykode, t_fdf *fdf);
int				mouse_move(int x, int y, t_fdf *fdf);
int				mouse_release(int btn, int x, int y, t_fdf *fdf);
int				mouse_press(int btn, int x, int y, t_fdf *fdf);

//-------------------------color.c
double percent(double start, double end, double current);
#endif
