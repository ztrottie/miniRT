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

int	put_color(t_ray ray)
{
	t_vec	unit_direction;
	t_vec	n;
	t_color	color;
	double	t;
	float	a;

	t = hit_sphere(init_vec(0, 0, -1), 0.5, ray);
	if (t > 0)
	{
		n = normalize_vector(vec_sub_vec(ray_at(ray, t), init_vec(0, 0, -1)));
		color = vec_mult(0.5, init_vec(n.x + 1, n.y + 1, n.z + 1));
		return (get_color(color));
	}
	unit_direction = normalize_vector(ray.dir);
	a = 0.5*(unit_direction.y + 1);
	color = vec_add(vec_mult((1 - a), init_vec(1, 1, 1)), vec_mult(a, init_vec(0.5, 0.7, 1)));
	return (get_color(color));
}
