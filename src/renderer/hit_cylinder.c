#include "../../include/renderer.h"

int	quadratic_cylinder(t_quad_cyl *quad, t_objs *cyl, t_ray ray, int t_max)
{
	quad->disc = sqr(quad->half_b) - quad->a * quad->c;
	if (quad->disc < 0)
		return (INVALID);
	quad->sqrtd = sqrt(quad->disc);
	quad->t = (-quad->half_b - quad->sqrtd) / quad->a;
	quad->m = dot_product(ray.dir, cyl->normal) * \
	quad->t + dot_product(quad->x, cyl->normal);
	if ((quad->t <= T_MIN || quad->t >= t_max) || \
	(quad->m < T_MIN || quad->m > cyl->height))
	{
		quad->t = (-quad->half_b + quad->sqrtd) / quad->a;
		quad->m = dot_product(ray.dir, cyl->normal) * \
		quad->t + dot_product(quad->x, cyl->normal);
		if ((quad->t < T_MIN || quad->t >= t_max) || \
		(quad->m < T_MIN || quad->m > cyl->height))
			return (INVALID);
	}
	return (VALID);
}

t_hitrec	hit_cylinder(t_objs	*cyl, t_ray ray, int t_max)
{
	t_hitrec	hitrec;
	t_quad_cyl	quad;

	quad.a = dot_product(ray.dir, ray.dir) - \
	sqr(dot_product(ray.dir, cyl->normal));
	quad.x = vec_sub_vec(ray.or, cyl->center);
	quad.half_b = dot_product(ray.dir, quad.x) - \
	dot_product(ray.dir, cyl->normal) * dot_product(quad.x, cyl->normal);
	quad.c = dot_product(quad.x, quad.x) - \
	sqr(dot_product(quad.x, cyl->normal)) - sqr(cyl->radius);
	if (quadratic_cylinder(&quad, cyl, ray, t_max) == INVALID)
		return (hitrec.hit = false, hitrec);
	hitrec.hit = true;
	hitrec.t = quad.t;
	hitrec.hitpoint = ray_at(ray, hitrec.t);
	hitrec.normal = normalize(vec_sub_vec(\
	vec_sub_vec(hitrec.hitpoint, cyl->center), vec_mult(quad.m, cyl->normal)));
	if (dot_product(hitrec.normal, ray.dir) > 0)
		hitrec.normal = vec_mult(-1, hitrec.normal);
	hitrec.material = cyl->material;
	hitrec.hitpoint = ray_at(init_ray(hitrec.hitpoint, \
	hitrec.normal), 0.00000000001);
	hitrec.type = 1;
	hitrec.inst = cyl;
	return (hitrec);
}
