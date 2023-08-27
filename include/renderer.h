#ifndef RENDERER_H
# define RENDERER_H

# include "minirt.h"

int 	get_rgba(int r, int g, int b, int a);
t_ray	init_ray(t_vec or, t_vec dir);
t_vec	init_vector(double x, double y, double z);
int		get_color(t_color color);

#endif