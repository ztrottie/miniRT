# include "../../include/maths.h"

double	hit_sphere(t_vec center, double radius, t_ray ray)
{
	t_vec	oc;
	double	a;
	double	half_b;
	double	c;
	double	discriminant;

	oc = vec_sub_vec(ray.or, center);
	a = sqr(vector_length(ray.dir));
	half_b = dot_product(oc, ray.dir);
	c = sqr(vector_length(oc)) - sqr(radius);
	discriminant = sqr(half_b) - a * c;
	if (discriminant < 0)
		return (-1);
	return (-half_b - sqrt(discriminant) / a);
}
