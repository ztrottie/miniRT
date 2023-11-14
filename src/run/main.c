#include "../../include/run.h"
#include <fcntl.h>

void	init_data(t_data *data)
{
	double	aspect_ratio;

	ft_bzero(data, sizeof (t_data));
	aspect_ratio = 16.0 / 9.0;
	data->img_height = WIDTH / aspect_ratio;
	data->cam_dir = normalize(init_vec(0, 0.05, -1));
	data->cam = init_vec(0, 3, 100);
	data->fov = 70;
}

int	main(int argc, char **argv)
{
	t_data data;

	(void)argc;
	(void)argv;
	init_data(&data);
	data.mlx = mlx_init(WIDTH, data.img_height, TITLE, false);
	data.mlx_image = mlx_new_image(data.mlx, WIDTH, data.img_height);
	data.objs = ft_calloc(6, sizeof(t_objs));
	data.nb_objs = 6;

	data.objs[0].center = init_vec(0.60, 0, -2);
	data.objs[0].radius = 1;
	data.objs[0].material.color = normalize(init_vec(0, 0, 255));
	data.objs[0].intersect_function = &hit_sphere;

	data.objs[1].center = init_vec(0, 3, -2);
	data.objs[1].radius = 0.5;
	data.objs[1].material.color = normalize(init_vec(0, 255, 0));
	data.objs[1].normal = normalize(init_vec(0, 0, 1));
	data.objs[1].height = 3;
	data.objs[1].intersect_function = &hit_cylinder;

	data.objs[2].center = init_vec(0, 2, -5);
	data.objs[2].normal = init_vec(0, 0, 1);
	data.objs[2].material.color = normalize(init_vec(0, 0, 255));
	data.objs[2].intersect_function = &hit_plane;

	data.objs[3].center = init_vec(0, -1, -1);
	data.objs[3].material.color = normalize(init_vec(100, 160, 200));
	data.objs[3].normal = init_vec(0, 1, 0);
	data.objs[3].intersect_function = &hit_plane;

	data.objs[4].center = init_vec(0, 0, -30);
	data.objs[4].radius = 1;
	data.objs[4].material.color = normalize(init_vec(0, 0, 255));
	data.objs[4].intersect_function = &hit_sphere;

	data.objs[5].center = init_vec(0, 3.10, -2);
	data.objs[5].radius = 0.60;
	data.objs[5].material.color = normalize(init_vec(0, 0, 255));
	data.objs[5].intersect_function = &hit_sphere;

	data.alight.material.bright = 0.2;

	data.light.center = init_vec(0, 10, 20);
	data.light.material.bright = 1;

	ray_tracer(&data);
	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
