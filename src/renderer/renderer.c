#include "../../include/renderer.h"

void	ray_gen(t_data *data, t_rend *rend)
{
	t_viewport	*vp;

	vp = &data->final_vp;
	rend->delta = vec_add(vec_mult(rend->i, vp->delta_v), vec_mult(rend->j, vp->delta_u));
	rend->p_center = vec_add(vp->p00_loc, rend->delta);
	rend->ray_direction = normalize(vec_sub_vec(rend->p_center, data->cam));
	rend->ray = init_ray(data->cam, rend->ray_direction);
}

void	ray_loop(t_data *data)
{
	t_rend		rend;

	final_viewport(data);
	rend.j = 0;
	while (rend.j < data->img_height)
	{
		rend.i = 0;
		while (rend.i < WIDTH)
		{
			ray_gen(data, &rend);
			mlx_put_pixel(data->mlx_image, rend.i, rend.j, put_color(data, rend.ray));
			rend.i++;
		}
		rend.j++;
	}
	mlx_image_to_window(data->mlx, data->mlx_image, 0, 0);
}
