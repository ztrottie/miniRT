#include "../../include/run.h"

void	cam_rotation(mlx_key_data_t keydata, t_data *data)
{
		if (keydata.key == MLX_KEY_UP)
		{
			if (data->pitch < 90)
				data->pitch++;;
		}
		else if (keydata.key == MLX_KEY_DOWN)
		{
			if (data->pitch > -90)
				data->pitch--;
		}
		if (keydata.key == MLX_KEY_LEFT)
		{
			data->yaw++;
			if (data->yaw >= 181)
				data->yaw = -179;
		}
		if (keydata.key == MLX_KEY_RIGHT)
		{
			data->yaw--;
			if (data->yaw <= -181)
				data->yaw = 179;
		}
}

void	objs_rotation(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_W)
		data->selected.objs->normal = rotation_x(data->selected.objs->normal, ++data->selected.x);
	else if (keydata.key == MLX_KEY_S)
		data->selected.objs->normal = rotation_x(data->selected.objs->normal, --data->selected.x);
	else if (keydata.key == MLX_KEY_A)
		data->selected.objs->normal = rotation_z(data->selected.objs->normal, ++data->selected.z);
	else if (keydata.key == MLX_KEY_D)
		data->selected.objs->normal = rotation_z(data->selected.objs->normal, --data->selected.z);
	else if (keydata.key == MLX_KEY_E)
		data->selected.objs->normal = rotation_y(data->selected.objs->normal, ++data->selected.y);
	else if (keydata.key == MLX_KEY_Q)
		data->selected.objs->normal = rotation_y(data->selected.objs->normal, --data->selected.y);
}

void	obj_movement(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_W)
		data->selected.objs->center.x++;
	else if (keydata.key == MLX_KEY_S)
		data->selected.objs->center.x--;
	else if (keydata.key == MLX_KEY_A)
		data->selected.objs->center.z++;
	else if (keydata.key == MLX_KEY_D)
		data->selected.objs->center.z--;
	else if (keydata.key == MLX_KEY_E)
		data->selected.objs->center.y++;
	else if (keydata.key == MLX_KEY_Q)
		data->selected.objs->center.y--;
}

void	cam_movement(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_W)
		data->cam = vec_add(data->cam, data->dir_foward);
	else if (keydata.key == MLX_KEY_S)
		data->cam = vec_add(data->cam, vec_mult(-1, data->dir_foward));
	else if (keydata.key == MLX_KEY_A)
		data->cam = vec_add(data->cam, vec_mult(-1, data->dir_right));
	else if (keydata.key == MLX_KEY_D)
		data->cam = vec_add(data->cam, data->dir_right);
	else if (keydata.key == MLX_KEY_E)
		data->cam = vec_add(data->cam, data->dir_down);
	else if (keydata.key == MLX_KEY_Q)
		data->cam = vec_add(data->cam, vec_mult(-1, data->dir_down));
}

void	movement_handler(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (!data->selected.objs)
		{
			cam_movement(keydata, data);
			cam_rotation(keydata, data);
		}
		else if (!data->rot_mod)
			obj_movement(keydata, data);
		else if (data->rot_mod)
			objs_rotation(keydata, data);
		if (keydata.key == MLX_KEY_SPACE)
			data->selected.objs = NULL;
		if (keydata.key == MLX_KEY_R)
			data->rot_mod = !data->rot_mod;
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(data->mlx);
			return;
		}
		ray_loop(data);
	}
}
