/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:01:05 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/11/21 20:01:06 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "minirt.h"
# include "maths.h"

typedef struct s_quad_sphere
{
	double	a;
	double	half_b;
	double	c;
	double	disc;
	double	sqrtd;
	t_vec	oc;
}	t_quad_sphere;

typedef struct s_quad_cyl
{
	double	a;
	double	half_b;
	double	c;
	double	disc;
	double	sqrtd;
	double	t;
	double	m;
	t_vec	x;
}	t_quad_cyl;

typedef struct s_rend
{
	t_vec	ray_direction;
	t_ray	ray;
	t_vec	p_center;
	t_vec	delta;
	int		i;
	int		j;
}	t_rend;

int			get_rgba(int r, int g, int b, int a);
t_ray		init_ray(t_vec or, t_vec dir);
t_vec		init_vec(double x, double y, double z);
int			get_color(t_color color);
int			put_color(t_data *data, t_ray ray);
void		ray_loop(t_data *data);
t_hitrec	ray_collisions(t_data *data, t_ray ray, int t_max);
t_hitrec	hit_light(t_data *data, t_hitrec hitrec);
t_hitrec	hit_plane(t_objs *plane, t_ray ray, int t_max);
t_hitrec	hit_cylinder(t_objs	*cyl, t_ray ray, int t_max);
t_hitrec	hit_sphere(t_objs *sphere, t_ray ray, int t_max);
void		final_viewport(t_data *data);
void		ray_gen(t_data *data, t_rend *rend);

#endif