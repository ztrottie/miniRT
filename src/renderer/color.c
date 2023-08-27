#include "../../include/renderer.h"

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int	get_color(t_color color)
{
	int	r;
	int g;
	int b;

	r = color.x * 255;
	g = color.y * 255;
	b = color.z * 255;
	return (get_rgba(r, g, b, 255));
}
