#include "../../include/renderer.h"

static t_vec	vp_upper_left(t_data *data, t_viewport *vp)
{
	t_vec	v1;
	t_vec	v2;

	v1 = vec_sub_vec(data->cam, init_vec(0, 0, vp->focal_len));
	v2 = vec_sub_vec(v1, vec_div(2, vp->vp_u));
	return (vec_sub_vec(v2, vec_div(2, vp->vp_v)));
}

static t_vec	vp_p00_loc(t_viewport *vp)
{
	t_vec	v1;
	
	v1 = vec_add(vp->delta_u, vp->delta_v);
	return (vec_add(vp->upper_left, vec_mult(0.5, v1)));
}

static void	init_viewport(t_data *data, t_viewport *vp)
{
	vp->vp_height = 2.0;
	vp->vp_width = vp->vp_height * (((double)WIDTH / data->img_height));
	vp->focal_len = (vp->vp_width / 2) / tan(data->fov / 2);
	vp->vp_center = vec_sub_vec(data->cam, init_vec(0, 0, vp->focal_len));
	vp->vp_v = init_vec(vp->vp_width, 0, 0);
	vp->vp_u = init_vec(0, -vp->vp_height, 0);
	vp->delta_v = vec_div(WIDTH, vp->vp_v);
	vp->delta_u = vec_div(data->img_height, vp->vp_u);
	vp->upper_left = vp_upper_left(data, vp);
	vp->p00_loc = vp_p00_loc(vp);
}

void	ray_tracer(t_data *data)
{
	int			i;
	int			j;
	t_viewport	vp;
	t_vec		delta;
	t_vec		p_center;
	t_vec		ray_direction;
	t_ray		ray;

	init_viewport(data, &vp);
	j = 0;
	while (j < data->img_height)
	{
		i = 0;
		while (i < WIDTH)
		{
			delta = vec_add(vec_mult(i, vp.delta_v), vec_mult(j, vp.delta_u));
			p_center = vec_add(vp.p00_loc, delta);
			ray_direction = normalize(vec_sub_vec(p_center, data->cam));
			ray = init_ray(data->cam, ray_direction);
			mlx_put_pixel(data->mlx_image, i, j, put_color(data, ray));
			i++;
		}
		j++;
	}
}
