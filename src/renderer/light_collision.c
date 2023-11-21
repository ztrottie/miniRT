#include "../../include/renderer.h"

t_hitrec	hit_light(t_data *data, t_hitrec hitrec)
{
	t_ray		ray;
	t_vec		ray_direction;
	t_vec		ambient_color;
	t_hitrec	hitrec2;
	double		bright;

	ambient_color = vec_mult(data->alight.material.bright, vec_add(data->alight.material.color, hitrec.material.color));
	ray_direction = normalize(vec_sub_vec(data->light.center, hitrec.hitpoint));
	ray = init_ray(hitrec.hitpoint, ray_direction);
	hitrec2 = ray_collisions(data, ray, vec_dist(hitrec.hitpoint, data->light.center));
	if (hitrec2.hit)
		hitrec.material.color = ambient_color;
	else
	{
		bright = dot_product(hitrec.normal, ray_direction) * data->light.material.bright;
		hitrec.material.color = vec_add(vec_mult(bright, hitrec.material.color), ambient_color);
	}
	return (hitrec);
}
