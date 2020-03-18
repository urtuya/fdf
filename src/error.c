#include "head.h"

void		print_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

void		check_malloc(void *data)
{
	if (!data)
		print_error("malloc error");
}

void		print_help(t_map *map)
{
	mlx_string_put(map->mlx, map->win, 20, 20, 0xFFFFFF,
							"Change projection: 1/2");
	mlx_string_put(map->mlx, map->win, 20, 40, 0xFFFFFF,
							"Change height: +/-");
	mlx_string_put(map->mlx, map->win, 20, 60, 0xFFFFFF,
							"Change color: 3/'z'(default)");
	mlx_string_put(map->mlx, map->win, 20, 80, 0xFFFFFF,
							"Change zoom: mouse scroll up/down");
}

void		usage()
{
	ft_putstr_fd("Usage: ./fdf [file] [color_start, color_end]\n", 2);
	ft_putstr_fd("\n color\t: color in hex (Ex. 0xffffff)\n", 2);
	exit(1);
}