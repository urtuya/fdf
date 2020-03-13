#include "head.h"

void		print_error(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
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
