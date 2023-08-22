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
double	discriminant(double a, double b, double c);
int		quadratic_formula(t_quad *quad)

#endif