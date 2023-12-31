/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:58:02 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/11/21 19:58:03 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/renderer.h"

t_hitrec	hit_plane(t_objs *plane, t_ray ray, int t_max)
{
	t_hitrec	hitrec;
	t_vec		x;
	double		a;
	double		b;

	hitrec.hit = false;
	x = vec_mult(-1, vec_sub_vec(ray.or, plane->center));
	a = dot_product(x, plane->normal);
	b = dot_product(ray.dir, plane->normal);
	if (b == 0 || a == 0)
		return (hitrec);
	hitrec.t = a / b;
	if (hitrec.t <= T_MIN || t_max <= hitrec.t)
		return (hitrec);
	hitrec.hit = true;
	hitrec.hitpoint = ray_at(ray, hitrec.t);
	hitrec.material = plane->material;
	hitrec.type = 0;
	if (b < 0)
		hitrec.normal = plane->normal;
	else
		hitrec.normal = vec_mult(-1, plane->normal);
	hitrec.hitpoint = ray_at(init_ray(hitrec.hitpoint, \
	hitrec.normal), 0.00000000001);
	return (hitrec.inst = plane, hitrec);
}
