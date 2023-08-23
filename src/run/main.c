#include "../../include/run.h"

t_vec	init_vector(double x, double y, double z)
{
	t_vec	new_vec;

	new_vec.x = x;
	new_vec.y = y;
	new_vec.z = z;
	return (new_vec);
}

t_ray	init_ray(t_vec or, t_vec dir)
{
	t_ray	ray;

	ray.dir = dir;
	ray.or = or;
	return (ray);
}

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof (t_data));
	data->viewport_height = 2;
	data->viewport_width = data->viewport_height * ((double)WIDTH / HEIGHT);
	data->cam = init_vector(0 , 0 , 0);
}

void	ray_tracer(t_data *data)
{
	int		i;
	int		j;
	double	pixel_detlta_v;
	double	pixel_detlta_u;
	t_ray	ray;
	t_vec	viewport_u;
	t_vec	viewport_v;
	t_vec	upper_left;
	t_vec	pixel00_loc;
	t_vec	pixel_center;
	t_vec	ray_direction;

	viewport_u = init_vector(data->viewport_width, 0, 0);
	viewport_v = init_vector(0, -data->viewport_height, 0);
	pixel_detlta_u = vec_div(WIDTH, viewport_u);
	pixel_detlta_v = vec_div(HEIGHT, viewport_v);
	upper_left = vec_sub(vec_sub_vec(vec_sub_vec(data->cam, init_vector(0, 0, -1)), vec_sub_nb(vec_div(2, viewport_u), vec_div(2, viewport_v))));
	pixel00_loc = vec_add(upper_left, vec_div(2, vec_add(pixel_detlta_u, pixel_detlta_v)));
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			pixel_center = vec_add(pixel00_loc, vec_add(vec_mult(i, pixel_detlta_u), vec_add(j, pixel_detlta_v)));
			ray_direction = vec_sub_vec(pixel_center, data->cam);
			ray = init_ray(data->cam, ray_direction);
			j++;
		}
		i++
	}
}

int	main(int argc, char **argv)
{
	t_data data;

	(void)argc;
	(void)argv;
	init_data(&data);
	data.mlx = mlx_init(WIDTH, HEIGHT, TITLE, false);
	ray_tracer(&data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
