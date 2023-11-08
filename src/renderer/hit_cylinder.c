#include "../../include/renderer.h"

int		quadratic_cylinder(t_quad_cyl *quad, t_objs cyl, t_ray ray, double *m)
{
	quad->disc = sqr(quad->half_b) - quad->a * quad->c;
	if (quad->disc < 0)
		return (INVALID);
	quad->sqrtd = sqrt(quad->disc);
	quad->t = (-quad->half_b - quad->sqrtd) / quad->a;
	*m = dot_product(ray.dir, cyl.normal) * quad->t + dot_product(quad->x, cyl.normal);
	printf("t1 t: %f m: %f\n", quad->t, *m);
	if ((quad->t <= T_MIN || quad->t >= T_MAX) || (*m < T_MIN || *m > cyl.height))
	{
		quad->t = (-quad->half_b + quad->sqrtd) / quad->a;
		*m = dot_product(ray.dir, cyl.normal) * quad->t + dot_product(quad->x, cyl.normal);
		printf("t2 t: %f m: %f\n", quad->t, *m);
		if ((quad->t <= T_MIN || quad->t >= T_MAX) || (*m < T_MIN || *m > cyl.height))
			return (INVALID);
	}
	printf("tf t: %f m: %f\n", quad->t, *m);
	return (VALID);
}

t_hitrec	hit_cylinder(t_objs	cyl, t_ray ray)
{
	t_hitrec	hitrec;
	t_quad_cyl	quad;
	double		m;

	quad.a = dot_product(ray.dir, ray.dir) - sqr(dot_product(ray.dir, cyl.normal));
	quad.x = vec_sub_vec(ray.or, cyl.center);
	quad.half_b = dot_product(ray.dir, quad.x) - dot_product(ray.dir, cyl.normal) * dot_product(quad.x, cyl.normal);
	quad.c = dot_product(quad.x, quad.x) - sqr(dot_product(quad.x, cyl.normal)) - sqr(cyl.radius);
	if (quadratic_cylinder(&quad, cyl, ray, &m) == INVALID)
		return (hitrec.hit = false, hitrec);
	hitrec.hit = true;
	hitrec.hitpoint = vec_add(ray.or, vec_mult(hitrec.t - 1e-4, ray.dir));
	hitrec.normal = normalize(vec_sub_vec(vec_sub_vec(hitrec.hitpoint, cyl.center), vec_mult(m, cyl.normal)));
	// if (dot_product(hitrec.normal, ray.dir) < 0)
	// 	hitrec.normal = vec_mult(-1, hitrec.normal);
	hitrec.material = cyl.material;
	return (hitrec);
}
