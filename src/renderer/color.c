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

int	put_color(t_data *data, t_ray ray)
{
	t_hitrec	hitrec;
	t_vec		unit_direction;
	t_color		color;
	float		a;

	hitrec = ray_collisions(data, ray);
	if (hitrec.hit)
		return (get_color(normalize(hitrec.material.color)));
	unit_direction = normalize(ray.dir);
	a = 0.5*(unit_direction.y + 1);
	color = vec_add(vec_mult((1 - a), init_vec(1, 1, 1)), vec_mult(a, init_vec(0.5, 0.7, 1)));
	return (get_color(color));
}
