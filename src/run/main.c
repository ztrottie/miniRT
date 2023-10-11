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

int	main(int argc, char **argv)
{
	t_data data;

	(void)argc;
	(void)argv;
	init_data(&data);
	data.mlx = mlx_init(WIDTH, data.img_height, TITLE, false);
	data.mlx_image = mlx_new_image(data.mlx, WIDTH, data.img_height);
	data.objs.sphere = ft_calloc(4, sizeof(t_sphere));

	data.fd = open("maps/map.rt", O_RDONLY);
	data.map = split_line(&data);

	data.nb_sphere = 4;
	data.objs.sphere[0].center = init_vec(1, 0, -3);
	data.objs.sphere[0].radius = 0.5;
	data.objs.sphere[0].material.color = normalize(init_vec(255, 0, 255));

	data.objs.sphere[1].center = init_vec(0, 0, -2);
	data.objs.sphere[1].radius = 0.5;
	data.objs.sphere[1].material.color = normalize(init_vec(222, 8, 152));

	data.objs.sphere[2].center = init_vec(-1, 0, -3);
	data.objs.sphere[2].radius = 0.5;
	data.objs.sphere[2].material.color = normalize(init_vec(0, 0, 255));

	data.objs.sphere[3].center = init_vec(0, -4.35, -3);
	data.objs.sphere[3].radius = 4;
	data.objs.sphere[3].material.color = normalize(init_vec(100, 160, 200));

	data.alight.material.bright = 0.2;

	data.light.center = init_vec(-5, 10, 10);
	data.light.material.bright = 1;

	ray_tracer(&data);
	mlx_image_to_window(data.mlx, data.mlx_image, 0, 0);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
