# include "../../include/renderer.h"

t_hitrec	hit_sphere(t_objs sphere, t_ray ray)
{
	t_hitrec		hitrec;
	t_quad_sphere	quad;

	quad.oc = vec_sub_vec(ray.or, sphere.center);
	quad.a = sqr(vector_length(ray.dir));
	quad.half_b = dot_product(quad.oc, ray.dir);
	quad.c = sqr(vector_length(quad.oc)) - sqr(sphere.radius);
	quad.disc = sqr(quad.half_b) - quad.a * quad.c;
	if (quad.disc < 0)
		return (hitrec.hit = false, hitrec);
	quad.sqrtd = sqrt(quad.disc);
	hitrec.t = (-quad.half_b - quad.sqrtd) / quad.a;
	if (hitrec.t <= T_MIN || T_MAX <= hitrec.t)
	{
		hitrec.t = (-quad.half_b + quad.sqrtd) / quad.a;
		if (hitrec.t <= T_MIN || T_MAX <= hitrec.t)
			return (hitrec.hit = false, hitrec);
	}
	hitrec.hit = true;
	hitrec.hitpoint = vec_add(ray.or, vec_mult(hitrec.t - 1e-4, ray.dir));
	hitrec.normal = normalize(vec_sub_vec(hitrec.hitpoint, sphere.center));
	hitrec.material = sphere.material;
	return (hitrec);
}
