#include "head.h"

double percent(double start, double end, double current)
{
    double placement;
    double distance;

    placement = current - start;
    distance = end - start;
    return ((distance == 0) ? 1.0 : (placement / distance));
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_line ln, t_coor cr1, t_coor cr2)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (ln.color == cr2.color)
		return (ln.color);
	if (ln.dx > ln.dy)
		percentage = percent((double)cr1.x, (double)cr2.x, (double)ln.x);
	else
		percentage = percent((double)cr1.y, (double)cr2.y, (double)ln.y);
	red = get_light((cr1.color >> 16) & 0xFF, (cr2.color >> 16) & 0xFF, percentage);
	green = get_light((cr1.color >> 8) & 0xFF, (cr2.color >> 8) & 0xFF, percentage);
	blue = get_light(cr1.color & 0xFF, cr2.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}