#include "../../include/run.h"

int	main(int argc, char **argv)
{
	t_data data;

	(void)argc;
	(void)argv;
	data.mlx = mlx_init(WIDTH, HEIGHT, TITLE, false);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (0);
}
