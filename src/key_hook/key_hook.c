#include "../../../include/minirt.h"

void	ft_movement_handler(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		// if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		// 	move_player(game, -1, 0);
		// else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		// 	move_player(game, 1, 0);
		// else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		// 	move_player(game, 0, -1);
		// else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		// 	move_player(game, 0, 1);
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(data->mlx);
		}
	}
}