#include "../../include/maths.h"

t_point	ray_at(t_ray ray, double t)
{
	return (vec_add(ray.or, vec_mult(t, ray.dir)));
}

double	vec_dist(t_vec v1, t_vec v2)
{
	double	t;

	t = sqrt(sqr(v2.x - v1.x) + sqr(v2.y - v1.y) + sqr(v2.z - v1.z));
	return (t);
}

double	vector_length(t_vec vec)
{
	return (sqrt(sqr(vec.x) + sqr(vec.y) + sqr(vec.z)));
}

t_vec	normalize(t_vec vec)
{
	double	vec_len;

	vec_len = vector_length(vec);
	return (vec_div(vec_len, vec));
}
