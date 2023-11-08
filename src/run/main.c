#include "../../include/run.h"
#include <fcntl.h>

void	init_data(t_data *data)
{
	double	aspect_ratio;

	ft_bzero(data, sizeof (t_data));
	aspect_ratio = 16.0 / 9.0;
	data->img_height = WIDTH / aspect_ratio;
	data->cam = init_vec(0, 0, 12);
	data->fov = 70;
}

int	main(int ac, char **av)
{
	t_data data;

	(void)ac;
	(void)av;
	init_data(&data);
	data.mlx = mlx_init(WIDTH, data.img_height, TITLE, false);
	data.mlx_image = mlx_new_image(data.mlx, WIDTH, data.img_height);
	data.objs = ft_calloc(3, sizeof(t_objs));
	data.nb_objs = 3;
	run_map(&data, av[1]);

	// data.objs[0].center = init_vec(1, 0, -3);
	// data.objs[0].radius = 0.5;
	// data.objs[0].material.color = normalize(init_vec(255, 0, 255));
	// data.objs[0].intersect_function = &hit_sphere;

	// data.objs[1].center = init_vec(0, 0, -2);
	// data.objs[1].radius = 0.5;
	// data.objs[1].material.color = normalize(init_vec(222, 8, 152));
	// data.objs[1].intersect_function = &hit_sphere;

	// data.objs[2].center = init_vec(-1, 0, -3);
	// data.objs[2].radius = 0.5;
	// data.objs[2].material.color = normalize(init_vec(0, 0, 255));
	// data.objs[2].intersect_function = &hit_sphere;

	// data.objs[3].center = init_vec(0, -1, -1);
	// data.objs[3].material.color = normalize(init_vec(100, 160, 200));
	// data.objs[3].normal = init_vec(0, 1, 0);
	// data.objs[3].intersect_function = &hit_plane;

	// data.alight.material.bright = 0.2;

	// data.light.center = init_vec(0, 10, 0);
	// data.light.material.bright = 1;

	ray_tracer(&data);
	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
