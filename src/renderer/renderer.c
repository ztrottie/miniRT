#include "../../include/renderer.h"

static void	upperleft(t_data *data, t_viewport *vp)
{
	t_vec	left_point;
	int		deg;

	deg = 90;
	left_point = ray_at(init_ray(vp->vp_center, rotation_y(data->cam_dir, 90)), vp->vp_width / 2);
	if (data->cam_dir.z > 0)
		deg *= -1;
	vp->upper_left = ray_at(init_ray(left_point, rotation_x(data->cam_dir, deg)), vp->vp_height / 2);
	vp->p00_loc = vec_add(vec_add(vp->upper_left, vec_div(2, vp->delta_v)), vec_div(2, vp->delta_u));
}

static void	init_viewport(t_data *data, t_viewport *vp)
{
	int 	deg;
	t_vec	dir;

	deg = -90;
	vp->vp_height = 2.0; 
	vp->vp_width = vp->vp_height * (((double)WIDTH / data->img_height));
	vp->focal_len = (vp->vp_width / 2) / tan(data->fov / 2);
	vp->vp_center = ray_at(init_ray(data->cam, data->cam_dir), vp->focal_len);
	dir.x = data->cam_dir.x;
	dir.y = 0;
	dir.z = data->cam_dir.z;
	vp->vp_v = ray_at(init_ray(vp->vp_center, rotation_y(dir, -90)), vp->vp_width);
	if (data->cam_dir.z > 0)
		deg *= -1;
	vp->vp_u = ray_at(init_ray(vp->vp_center, rotation_x(data->cam_dir, deg)), vp->vp_height);
	vp->delta_v = vec_div(WIDTH, vec_sub_vec(vp->vp_v, vp->vp_center));
	vp->delta_u = vec_div(data->img_height, vec_sub_vec(vp->vp_u, vp->vp_center));
	upperleft(data, vp);
	printf("%f, %f, %f\n", vp->vp_center.x, vp->vp_center.y, vp->vp_center.z);
	printf("%f, %f, %f\n", vp->vp_v.x, vp->vp_v.y, vp->vp_v.z);
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
