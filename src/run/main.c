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
	ft_memmove(data->type[0], "cy", 3);
	ft_memmove(data->type[1], "sp", 3);
	ft_memmove(data->type[2], "pl", 3);
}

int	main(int argc, char **argv)
{
	t_data data;

	init_data(&data);
	data.mlx = mlx_init(WIDTH, data.img_height, TITLE, false);
	data.mlx_image = mlx_new_image(data.mlx, WIDTH, data.img_height);
	if (argc == 1)
		map_error("Select a map in Scenes/something.rt");
	else
		run_map(&data, argv[1]);

	ray_tracer(&data);
	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
