#ifndef MATHS_H
# define MATHS_H

# include "minirt.h"

typedef struct s_quad
{
	int		nb_solution;
	double	disc;
	double	*solutions;
	double	a;
	double	b;
	double	c;
}	t_quad;

double	sqr(double a);
bool	hit_sphere(t_vec center, double radius, t_ray ray);
double	dot_product(t_vec v1, t_vec v2);
t_vec	vec_div(double div, t_vec v1);
t_vec	vec_mult(double mult, t_vec v1);
t_vec	vec_add(t_vec v1, t_vec v2);
t_vec	vec_sub_vec(t_vec v1, t_vec v2);
t_vec   vec_sub_nb(t_vec v1, double sub);
t_vec	vec_add_nb(t_vec v1, double add);
t_vec	normalize_vector(t_vec vec);
double	vector_length(t_vec vec);

#endif