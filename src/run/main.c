#include "../../include/run.h"

void	init_data(t_data *data)
{
	ft_bzero(data, sizeof (t_data));
	data->viewport_height = 2;
	data->viewport_width = data->viewport_height * ((double)WIDTH / HEIGHT);
}

int	open_map(t_data *data)
{
	
}

void	ray_tracer(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
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
