#include "../../include/renderer.h"

t_hitrec	hit_plane(t_objs plane, t_ray ray)
{
	t_hitrec	hitrec;
	t_vec		x;
	double		a;
	double		b;

	hitrec.hit = false;
	x = vec_mult(-1, vec_sub_vec(ray.or, plane.center));
	a = dot_product(x, plane.normal);
	b = dot_product(ray.dir, plane.normal);
	if (b == 0 || a == 0)
		return (hitrec);
	hitrec.t = a / b;
	if (hitrec.t <= T_MIN || T_MAX <= hitrec.t)
		return (hitrec);
	hitrec.hit = true;
	hitrec.hitpoint = vec_add(ray.or, vec_mult(hitrec.t - 1e-4, ray.dir));
	hitrec.material = plane.material;
	if (b < 0)
		hitrec.normal = vec_mult(-1, plane.normal);
	else
		hitrec.normal = plane.normal;
	return (hitrec);
}
