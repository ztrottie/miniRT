/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:57:46 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/11/21 19:57:47 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/renderer.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int	get_color(t_color color)
{
	double	r;
	double	g;
	double	b;

	r = fmin(255, color.x * 255.0);
	g = fmin(255, color.y * 255.0);
	b = fmin(255, color.z * 255.0);
	return (get_rgba(r, g, b, 255));
}

int	put_color(t_data *data, t_ray ray)
{
	t_hitrec	hitrec;
	t_color		color;
	float		a;

	hitrec = ray_collisions(data, ray, T_MAX);
	if (hitrec.hit)
	{
		hitrec = hit_light(data, hitrec);
		if (hitrec.hit)
		{
			return (get_color(hitrec.material.color));
		}
	}
	a = 0.5 * (ray.dir.y + 1);
	color = vec_add(vec_mult((1 - a), init_vec(1, 1, 1)), \
	vec_mult(a, init_vec(0.5, 0.7, 1)));
	return (get_color(color));
}
