#include "../../include/run.h"

void	init_rotations(t_data *data)
{
	double yaw;
	double x;
	double z;

	data->pitch = data->cam_dir.y * 90;
	x = data->cam_dir.x;
	z = data->cam_dir.z;
	yaw = atan2(-x, -z);
	data->yaw = yaw * 180.0 / M_PI;
}
