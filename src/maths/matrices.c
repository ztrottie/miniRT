#include "../../include/maths.h"

t_vec	rotation_z(t_vec vec, double deg)
{
	t_vec	result;

	deg = deg * (M_PI / 180);
	result.x = vec.x * cos(deg) + vec.y * -sin(deg);
	result.y = vec.x * sin(deg) + vec.y * cos(deg);
	result.z = vec.z;
	return (result);
}

t_vec	rotation_x(t_vec vec, double deg)
{
	t_vec	result;

	deg = deg * (M_PI / 180);
	result.x = vec.x;
	result.y = vec.y * cos(deg) + vec.z * -sin(deg);
	result.z = vec.y * sin(deg) + vec.z * cos(deg);
	return (result);
}

t_vec	rotation_y(t_vec vec, double deg)
{
	t_vec	result;

	deg = deg * (M_PI / 180);
	result.x = vec.x * cos(deg) + vec.z * sin(deg);
	result.y = vec.y;
	result.z = vec.x * -sin(deg) + vec.z * cos(deg);
	return (result);
}
