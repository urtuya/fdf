#include "head.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	// printf("st = %d end = %d curr = %d\n", start, end, current);
	placement = current - start;
	distance = end - current;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_color *color, t_line ln)
{
	double	percentage;
	int		r;
	int		g;
	int		b;

	if (color->curr == color->end)
		return (color->end);
	percentage = abs(ln.dx) > abs(ln.dy) ? percent(ln.xs, ln.x, ln.xe) : percent(ln.ys, ln.y, ln.ye);
	// printf("percent = %f\n", percentage);
	r = get_light((color->start >> 16) & 0xFF, (color->end >> 16) & 0xFF, percentage);
	g = get_light((color->start >> 8) & 0xFF, (color->end >> 8) & 0xFF, percentage);
	b = get_light(color->start & 0xFF, color->end & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}