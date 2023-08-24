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
	data->focal_length = 1;
	data->cam = init_vector(0, 0, 0);
}

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int	put_color(t_data *data, t_ray ray)
{
	t_vec	unit_direction;
	int		r;
	int		g;

	unit_direction = normalize_vector(ray.dir);
	if (hit_sphere(init_vector(-10, -7, -10), 1, ray))
		return (get_rgba(255, 0, 0, 255));
	r = fabs(unit_direction.y) * (255 / data->viewport_height);
	g = fabs(unit_direction.x) * (255 / data->viewport_width);
	return (get_rgba(r, g, 0, 255));
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
	printf("viewport_center |x:%f y:%f z:%f|\n", viewport_center.x, viewport_center.y, viewport_center.z);
	printf("delta_v |x:%f y:%f z:%f|\n", delta_v.x, delta_v.y, delta_v.z);
	printf("delta_u |x:%f y:%f z:%f|\n", delta_u.x, delta_u.y, delta_u.z);
	printf("upper_left |x:%f y:%f z:%f|\n", upper_left.x, upper_left.y, upper_left.z);
	printf("pixel00_loc |x:%f y:%f z:%f|\n", pixel00_loc.x, pixel00_loc.y, pixel00_loc.z);
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			ray_direction = vec_sub_vec(vec_add(pixel00_loc, vec_add(vec_mult(i, delta_v), vec_mult(j, delta_u))), data->cam);
			ray = init_ray(data->cam, ray_direction);
			mlx_put_pixel(data->mlx_image, i, j, put_color(data, ray));
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
