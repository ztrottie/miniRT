#include "../../include/run.h"


void	init_data(t_data *data)
{
	ft_bzero(data, sizeof (t_data));
	data->viewport_height = 2;
	data->viewport_width = data->viewport_height * ((double)WIDTH / HEIGHT);
	data->focal_length = 1;
	data->cam = init_vector(0, 0, 0);
}

int	put_color(t_ray ray)
{
	t_vec	unit_direction;
	t_vec	n;
	t_color	color;
	double	t;
	float	a;

	t = hit_sphere(init_vector(-1, 0, -1), 0.5, ray);
	if (t > 0)
	{
		n = normalize_vector(vec_sub_vec(ray_at(ray, t), init_vector(0, 0, -1)));
		color = vec_mult(0.5, init_vector(n.x + 1, n.y + 1, n.z + 1));
		return (get_color(color));
	}
	unit_direction = normalize_vector(ray.dir);
	a = 0.5*(unit_direction.y + 1);
	color = vec_add(vec_mult((1 - a), init_vector(1, 1, 1)), vec_mult(a, init_vector(0.5, 0.7, 1)));
	return (get_color(color));
}

void	ray_tracer(t_data *data)
{
	int		i;
	int		j;
	t_vec	ray_direction;
	t_ray	ray;
	t_vec	delta_v;
	t_vec	delta_u;
	t_vec	viewport_v;
	t_vec	viewport_u;
	t_vec	viewport_center;
	t_vec	upper_left;
	t_vec	pixel00_loc;

	viewport_center = vec_sub_vec(data->cam, init_vector(0, 0, data->focal_length));
	viewport_v = init_vector(data->viewport_width, 0, 0);
	viewport_u = init_vector(0, -data->viewport_height, 0);
	delta_v	= vec_div(WIDTH, viewport_v);
	delta_u = vec_div(HEIGHT, viewport_u);
	upper_left = vec_sub_vec(vec_sub_vec(vec_sub_vec(data->cam, init_vector(0, 0, data->focal_length)), vec_div(2, viewport_u)), vec_div(2, viewport_v));
	pixel00_loc = vec_add(upper_left, vec_mult(0.5, vec_add(delta_u, delta_v)));
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			ray_direction = vec_sub_vec(vec_add(pixel00_loc, vec_add(vec_mult(i, delta_v), vec_mult(j, delta_u))), data->cam);
			ray = init_ray(data->cam, ray_direction);
			mlx_put_pixel(data->mlx_image, i, j, put_color(ray));
			i++;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	t_data data;

	(void)argc;
	(void)argv;
	init_data(&data);
	data.mlx = mlx_init(WIDTH, HEIGHT, TITLE, false);
	data.mlx_image = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	ray_tracer(&data);
	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
