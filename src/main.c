/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 15:54:47 by oargrave          #+#    #+#             */
/*   Updated: 2019/10/27 16:12:20 by oargrave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void		apply_hooks(t_fdf *fdf)
{
	print_help(fdf->full);
	mlx_hook(fdf->full->win, 4, MOUSE_PRESS, mouse_press, fdf);
	mlx_hook(fdf->full->win, 5, MOUSE_RELEASE, mouse_release, fdf);
	mlx_hook(fdf->full->win, 6, MOUSE_MOVE, mouse_move, fdf);
	mlx_hook(fdf->full->win, 2, KEY_PRESS, key_press, fdf);
}

int			main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		print_error("Usage: ./fdf [file]");
	fdf = init_fdf(argv[1]);
	draw(fdf, fdf->proj == PARALLEL ? matrix : set_iso_coords);
	apply_hooks(fdf);
	mlx_loop(fdf->full->mlx);
	return (0);
}
