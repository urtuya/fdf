#include "head.h"




// void	draw_linex(t_fdf *fdf, t_coor cr1, int x, int y)
// {
// 	t_coor cr2;

// 	cr2.x = x + fdf->siz;
// 	cr2.y = y;
// 	if (x < HEI - fdf->offx)
// 		draw_line(fdf, cr1, cr2);
// }

// void	draw_liney(t_fdf *fdf, t_coor cr1, int x, int y)
// {
// 	t_coor cr2;

// 	cr2.x = x;
// 	cr2.y = y + fdf->siz;
// 	if (y < WID - fdf->offy)
// 		draw_line(fdf, cr1, cr2); // y
// }

// void	draw(t_fdf *fdf)
// {
// 	t_coor cr1;
// 	int i;
// 	int j;
// 	int k;


// 	k = 0;
// 	i = fdf->offx;
// 	while (i <= HEI - fdf->offx)
// 	{
// 		j = fdf->offy;
// 		while (j <= WID - fdf->offy)
// 		{
// 			cr1.x = i;
// 			cr1.y = j;
// 			if (fdf->map[k].z)
// 				fdf->color = 0xFFFFFF;
// 			else 
// 				fdf->color = 0xEE82EE;
// 			draw_linex(fdf, cr1, i, j);
// 			draw_liney(fdf, cr1, i, j);
// 			j += fdf->siz;
// 			k++;
// 		}
// 		i += fdf->siz;
// 	}
// }

// void	isometric(t_3dmap *arr)
// {
// 	double	prev_x;
// 	double	prev_y;

// 	prev_x = arr->x;
// 	prev_y = arr->y;

// 	arr->x = (prev_x - prev_y) * cos(0.523599);
// 	arr->y = -arr->z + (prev_x + prev_y) * sin(0.523599);
// }
// void	x_line(t_fdf *fdf, t_coor cr1, int y)
// {
// 	t_coor cr2;

// 	cr2.y = y + fdf->siz;;
// 	cr2.x = cr1.x + fdf->siz/ 2;
// 	// printf("x1 = %d y1 = %d\n", cr1.x, cr1.y);
// 	draw_line(fdf, cr1, cr2);
// }

// void	y_line(t_fdf *fdf, t_coor cr1, int x)
// {
// 	t_coor cr2;

// 	cr2.x = x + fdf->siz;
// 	cr2.y = cr1.y;
// 	draw_line(fdf, cr1, cr2);
// }



// void	draw_isometric(t_fdf *fdf)
// {
// 	// int i;
// 	// t_coor coor[fdf->map_len];

// 	// i = 0;
// 	// while (i < fdf->map_len)
// 	// {
// 	// 	isometric(&fdf->map[i]);
// 	// 	printf("%d: x = %f y = %f z = %f\n", i, fdf->map[i].x, fdf->map[i].y, fdf->map[i].z);
// 	// 	i++;
// 	// }

// 	// int j;
// 	// t_coor cr1, cr2;
// 	// int k = 0;
// 	// i = fdf->offx;
// 	// while (i <= HEI - fdf->offx)
// 	// {
// 	// 	j = fdf->offy;

// 	// 	while (j <= WID - fdf->offy)
// 	// 	{
// 	// 		cr1.x = i;
// 	// 		cr1.y = j;
// 	// 		if (fdf->map[k].z)
// 	// 			fdf->color = 0xFFFFFF;
// 	// 		else 
// 	// 			fdf->color = 0xEE82EE;
// 	// 		cr2.x = fdf->map[k].x + fdf->siz + fdf->offx;
// 	// 		cr2.y = fdf->map[k].y + fdf->offy;
// 	// 		draw_line(fdf, cr1, cr2);
// 	// 		// cr2.x = fdf->map[k].x + fdf->offx;
// 	// 		// cr2.y = fdf->map[k].y + fdf->siz + fdf->offy;
// 	// 		// draw_line(fdf, cr1, cr2);
// 	// 		k++;
// 	// 		j+= fdf->siz;
// 	// 	}
// 	// 	i += fdf->siz;
// 	// }

// 	int i;
// 	int j;
// 	t_coor cr1;
// 	t_coor cr2;

// 	fdf->color = 0xFF0000;
// 	// cr2.x = fdf->offx;
// 	// cr2.y = fdf->offy;
// 	// i = fdf->offx;
// 	// while (i <= HEI - fdf->offx)
// 	// {
// 	// 	j = fdf->offy;
// 	// 	while (j <= WID - fdf->offy)
// 	// 	{
// 	// 		cr1.x = cr2.x;
// 	// 		cr1.y = cr2.y;

// 	// 		cr2.y = j + fdf->siz;
// 	// 		cr2.x = i + (cr2.y - cr1.y) / 2;
// 	// 		draw_line(fdf, cr1, cr2);
// 	// 		// return ;
// 	// 		j += fdf->siz;
// 	// 	}
// 	// 	i += fdf->siz;
// 	// }
// 	cr2.x = fdf->offx;
// 	cr2.y = fdf->offy;


// int count = 0;
// printf("offx = %d offy = %d\n", fdf->offx, fdf->offy);
// printf("siz = %d\n", fdf->siz);
// 	i = fdf->offx;
// 	while (i <= HEI - fdf->offx)
// 	{
// 		cr2.x = i;
// 		j = fdf->offy;
// 		cr2.y = j;
// 		while (j <= WID - fdf->offy)
// 		{
// 			cr1.x = cr2.x;
// 			cr1.y = cr2.y; 
// 			x_line(fdf, cr1, j);
// 			y_line(fdf, cr1, i);
// 				// return ;
// 			j+= fdf->siz;
// 			count++;
// 		}
// 		i+=fdf->siz;
// 	}
// }

void	set_offset(t_fdf *fdf)
{
	double sizx;
	double sizy;

	
	fdf->x_err = fdf->hei / 2;
	fdf->y_err = fdf->wid / 2;
	fdf->siz = 20;
	// fdf->offx = HEI / 2;
	// fdf->offy = WID / 2;
	fdf->offy = HEI / 2;// (HEI - (fdf->hei * fdf->siz - fdf->siz)) / 2;
	fdf->offx = WID / 2; //(WID - (fdf->wid * fdf->siz - fdf->siz)) / 2;
}

static void	set_coords(t_3dmap *map, t_fdf *fdf)
{
	double	prev_x;
	double	prev_y;

	prev_x = map->x;
	prev_y = map->y;
	map->x = ((prev_x - prev_y) * cos(0.523599) * fdf->siz);
	map->y = (-map->z + (prev_x + prev_y) * sin(0.523599)) * fdf->siz;
	printf("[%d][%d] x = %.f y = %.f\n",(int)prev_x, (int)prev_y, map->x, map->y);
}



void	iso_coords(t_3dmap **map, t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->hei)
	{
		j = 0;
		while (j < fdf->wid)
		{
			set_coords(&map[i][j], fdf);
			j++;
		}
		i++;
	}
}

void	draw_lines(t_fdf *fdf, t_3dmap map1, t_3dmap map2)
{
	t_coor cr1;
	t_coor cr2;

	cr1.x = (int)map1.x;
	cr1.y = (int)map1.y;
	cr2.x = (int)map2.x;
	cr2.y = (int)map2.y;
	draw2(fdf, cr1, cr2);
}

void	draw_iso(t_fdf *fdf, t_3dmap **map)
{
	int i;
	int j;

	iso_coords(fdf->map, fdf);
	i = 0;
	while (i < fdf->hei)
	{
		j = 0;
		while (j < fdf->wid - 1)
		{
			// draw_lines(fdf, map[i][j], map[i + 1][j]);
			// return ;
			draw_lines(fdf, map[i][j], map[i][j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < fdf->hei - 1)
	{
		j = 0;
		while (j < fdf->wid)
		{
			draw_lines(fdf, map[i][j], map[i + 1][j]);
			j++;
		}
		i++;
	}
}

