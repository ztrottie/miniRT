/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:58:05 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/11/21 19:58:06 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/renderer.h"

t_hitrec	hit_sphere(t_objs *sphere, t_ray ray, int t_max)
{
	t_hitrec		hitrec;
	t_quad_sphere	quad;

	quad.oc = vec_sub_vec(ray.or, sphere->center);
	quad.half_b = dot_product(quad.oc, ray.dir);
	quad.c = sqr(vector_length(quad.oc)) - sqr(sphere->radius);
	quad.disc = sqr(quad.half_b) - quad.c;
	if (quad.disc < 0)
		return (hitrec.hit = false, hitrec);
	quad.sqrtd = sqrt(quad.disc);
	hitrec.t = (-quad.half_b - quad.sqrtd);
	if (hitrec.t <= T_MIN || t_max <= hitrec.t)
	{
		hitrec.t = (-quad.half_b + quad.sqrtd);
		if (hitrec.t <= T_MIN || t_max <= hitrec.t)
			return (hitrec.hit = false, hitrec);
	}
	hitrec.hitpoint = ray_at(ray, hitrec.t);
	hitrec.normal = normalize(vec_sub_vec(hitrec.hitpoint, sphere->center));
	if (dot_product(ray.dir, hitrec.normal) > 0)
		hitrec.normal = vec_mult(-1, hitrec.normal);
	hitrec.material = sphere->material;
	hitrec.hitpoint = ray_at(init_ray(hitrec.hitpoint, \
	hitrec.normal), 0.00000000001);
	return (hitrec.hit = true, hitrec.inst = sphere, hitrec);
}
