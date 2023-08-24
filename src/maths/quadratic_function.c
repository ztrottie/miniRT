# include "../../include/maths.h"

bool	hit_sphere(t_vec center, double radius, t_ray ray)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	oc = vec_sub_vec(ray.or, center);
	a = dot_product(ray.dir, ray.dir);
	b = 2 * dot_product(oc, ray.dir);
	c = dot_product(oc, oc) - sqr(radius);
	discriminant = sqr(b) - 4 * a * c;
	if (discriminant >= 0)
		return (true);
	return (false);
}
