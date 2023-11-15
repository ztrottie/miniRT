#include "../../include/run.h"

void	movement_handler(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			data->cam_dir.z += 1;
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			data->cam_dir.z -= 1;
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			data->cam_dir.x -= 1;
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			data->cam_dir.x += 1;
		else if (keydata.key == MLX_KEY_E)
			data->cam_dir.y += 1;
		else if (keydata.key == MLX_KEY_Q)
			data->cam_dir.y -= 1;
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(data->mlx);
		//init_viewport();
	}
}
