#ifndef RENDERER_H
# define RENDERER_H

# include "minirt.h"
# include "maths.h"

typedef struct s_quad
{
	double	a;
	double	half_b;
	double	c;
	double	disc;
	double	sqrtd;
	t_vec	oc;
}	t_quad;

typedef struct	s_viewport
{
	double	vp_height;
	double	vp_width;
	double	focal_len;
	t_vec	delta_v;
	t_vec	delta_u;
	t_vec	vp_v;
	t_vec	vp_u;
	t_vec	vp_center;
	t_vec	upper_left;
	t_vec	p00_loc;
}	t_viewport;

int 		get_rgba(int r, int g, int b, int a);
t_ray		init_ray(t_vec or, t_vec dir);
t_vec		init_vec(double x, double y, double z);
int			get_color(t_color color);
int			put_color(t_data *data, t_ray ray);
void		ray_tracer(t_data *data);
t_hitrec	ray_collisions(t_data *data, t_ray ray);

#endif