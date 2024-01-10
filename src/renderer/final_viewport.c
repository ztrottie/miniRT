/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_viewport.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:57:51 by zbeaumon          #+#    #+#             */
/*   Updated: 2024/01/10 16:45:41 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/run.h"

void	pitch(t_data *data)
{
	data->final_vp.delta_u = rotation_x(data->base_vp.delta_u, data->pitch);
	data->final_vp.delta_v = rotation_x(data->base_vp.delta_v, data->pitch);
	data->final_vp.p00_loc = rotation_x(data->base_vp.p00_loc, data->pitch);
	data->final_vp.vp_center = rotation_x(data->base_vp.vp_center, data->pitch);
}

void	yaw(t_data *data)
{
	data->final_vp.delta_u = rotation_y(data->final_vp.delta_u, data->yaw);
	data->final_vp.delta_v = rotation_y(data->final_vp.delta_v, data->yaw);
	data->final_vp.p00_loc = rotation_y(data->final_vp.p00_loc, data->yaw);
	data->final_vp.vp_center = rotation_y(data->base_vp.vp_center, data->yaw);
}

void	final_viewport(t_data *data)
{
	pitch(data);
	yaw(data);
	data->final_vp.p00_loc = vec_add(data->cam, data->final_vp.p00_loc);
	data->final_vp.vp_center = vec_add(data->cam, data->final_vp.vp_center);
	data->dir_down = normalize(data->final_vp.delta_u);
	data->dir_right = normalize(data->final_vp.delta_v);
	data->dir_foward = normalize(vec_sub_vec(data->final_vp.vp_center, \
	data->cam));
	printf("final vp: x:%f y:%f z:%f\n", data->final_vp.p00_loc.x, data->final_vp.p00_loc.y, data->final_vp.p00_loc.z);
}
