#include "../../include/renderer.h"

t_vec	init_vector(double x, double y, double z)
{
	t_vec	new_vec;

	new_vec.x = x;
	new_vec.y = y;
	new_vec.z = z;
	return (new_vec);
}

t_ray	init_ray(t_vec or, t_vec dir)
{
	t_ray	ray;

	ray.dir = dir;
	ray.or = or;
	return (ray);
}
