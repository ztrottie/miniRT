#include "../../include/run.h"
#include <fcntl.h>

static void	init_data(t_data *data)
{
	double	aspect_ratio;

	ft_bzero(data, sizeof (t_data));
	aspect_ratio = 16.0 / 9.0;
	data->img_height = WIDTH / aspect_ratio;
	data->count_light = 0;
	data->count_cam = 0;
	data->count_alight = 0;
	ft_memmove(data->type[0], "cy", 3);
	ft_memmove(data->type[1], "sp", 3);
	ft_memmove(data->type[2], "pl", 3);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	data.mlx = mlx_init(WIDTH, data.img_height, TITLE, false);
	data.mlx_image = mlx_new_image(data.mlx, WIDTH, data.img_height);
	if (argc == 1)
		map_error("Select a map in Scenes/something.rt");
	else
		run_map(&data, argv[1]);
	init_viewport(&data);
	init_rotations(&data);
	mlx_key_hook(data.mlx, movement_handler, &data);
	mlx_mouse_hook(data.mlx, mouse_hook, &data);
	ray_loop(&data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_x2free((void **)data.objs);
	return (0);
}
