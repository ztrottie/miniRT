#include "../../include/run.h"

void	pitch(t_data *data)
{
	double pitch;

	pitch = data->cam_dir.y * 90;
	printf("pitch x:%f\n", pitch);
	data->final_vp.delta_u = rotation_x(data->base_vp.delta_u, pitch);
	data->final_vp.delta_v = rotation_x(data->base_vp.delta_v, pitch);
	data->final_vp.p00_loc = rotation_x(data->base_vp.p00_loc, pitch);
}

void	yaw(t_data *data)
{
	double yaw;
	double x;
	double z;
	x = data->cam_dir.x;
	z = data->cam_dir.z;
	yaw = atan2(-x, -z);
	yaw = yaw * 180.0 / M_PI;
	printf("yaw: %f\n", yaw);
	data->final_vp.delta_u = rotation_y(data->final_vp.delta_u, yaw);
	data->final_vp.delta_v = rotation_y(data->final_vp.delta_v, yaw);
	data->final_vp.p00_loc = rotation_y(data->final_vp.p00_loc, yaw);
}

void	final_viewport(t_data *data)
{
	pitch(data);
	yaw(data);
	data->final_vp.p00_loc = vec_add(data->cam, data->final_vp.p00_loc);
}
