#include "../../include/maths.h"

t_point	ray_at(t_ray ray, double t)
{
	return (vec_add(ray.or, vec_mult(t, ray.dir)));
}
