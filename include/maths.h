#ifndef MATHS_H
# define MATHS_H

# include "minirt.h"

double		sqr(double a);
t_hitrec	hit_sphere(t_sphere sphere, t_ray ray, double t_max, double t_min);
double		dot_product(t_vec v1, t_vec v2);
t_vec		vec_div(double div, t_vec v1);
t_vec		vec_mult(double mult, t_vec v1);
t_vec		vec_add(t_vec v1, t_vec v2);
t_vec		vec_sub_vec(t_vec v1, t_vec v2);
t_vec   	vec_sub_nb(t_vec v1, double sub);
t_vec		vec_add_nb(t_vec v1, double add);
double		vec_dist(t_vec v1, t_vec v2);;
t_vec		normalize(t_vec vec);
double		vector_length(t_vec vec);
t_point		ray_at(t_ray ray, double t);

#endif