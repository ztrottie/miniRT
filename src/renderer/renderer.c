#include "../../include/renderer.h"

void	ray_gen(t_data *data, t_rend *rend, int i, int j)
{
	t_viewport	*vp;

	vp = &data->vp;
	rend->delta = vec_add(vec_mult(i, vp->delta_v), vec_mult(j, vp->delta_u));
	rend->p_center = vec_add(vp->p00_loc, rend->delta);
	rend->ray_direction = normalize(vec_sub_vec(rend->p_center, data->cam));
	rend->ray = init_ray(data->cam, rend->ray_direction);
}

void	ray_loop(t_data *data)
{
	t_rend		rend;
	t_viewport	*vp;

	vp = &data->vp;
	rend.j = 0;
	while (rend.j < data->img_height)
	{
		rend.i = 0;
		while (rend.i < WIDTH)
		{
			ray_gen(data, &rend, rend.i, rend.j);
			mlx_put_pixel(data->mlx_image, rend.i, rend.j, put_color(data, rend.ray));
			rend.i++;
		}
		rend.j++;
	}
}
