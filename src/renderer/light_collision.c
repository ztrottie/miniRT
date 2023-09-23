#include "../../include/renderer.h"

t_hitrec	hit_light(t_data *data, t_hitrec hitrec)
{
	t_ray		ray;
	t_vec		ray_direction;
	t_hitrec	hitrec2;

	ray_direction = vec_sub_vec(data->light.center, hitrec.hitpoint);
	ray = init_ray(hitrec.hitpoint, ray_direction);
	hitrec2 = ray_collisions(data, ray);
	if (hitrec2.hit)
	{
		hitrec2 = hitrec;
		hitrec2.material.color = vec_mult(data->alight.material.bright, hitrec2.material.color);
	}
	else
	{
		hitrec2 = hitrec;
		hitrec2.material.color = vec_mult(data->light.material.bright, hitrec2.material.color);
	}
	return (hitrec2);
}
