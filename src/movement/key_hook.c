/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:59:00 by zbeaumon          #+#    #+#             */
/*   Updated: 2024/01/10 16:47:35 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/run.h"

void	cam_rotation(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_UP)
	{
		if (data->pitch < 90)
			data->pitch++;
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
	t_selected	*selected;
	t_objs		*objs;

	selected = &data->selected;
	objs = selected->objs;
	if (keydata.key == MLX_KEY_W)
		objs->normal = rotation_x(objs->normal, 1);
	else if (keydata.key == MLX_KEY_S)
		objs->normal = rotation_x(objs->normal, -1);
	else if (keydata.key == MLX_KEY_A)
		objs->normal = rotation_z(objs->normal, 1);
	else if (keydata.key == MLX_KEY_D)
		objs->normal = rotation_z(objs->normal, -1);
	else if (keydata.key == MLX_KEY_E)
		objs->normal = rotation_y(objs->normal, 1);
	else if (keydata.key == MLX_KEY_Q)
		objs->normal = rotation_y(objs->normal, -1);
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
		data->cam = vec_add(data->cam, vec_mult(-1, data->dir_foward));
	else if (keydata.key == MLX_KEY_S)
		data->cam = vec_add(data->cam, data->dir_foward);
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
			return ;
		}
		ray_loop(data);
	}
}
