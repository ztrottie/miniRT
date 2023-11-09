#include "../../include/renderer.h"

t_hitrec	hit_light(t_data *data, t_hitrec hitrec)
{
	t_ray		ray;
	t_vec		ray_direction;
	t_hitrec	hitrec2;
	double		bright;

	ray_direction = normalize(vec_sub_vec(data->light.center, hitrec.hitpoint));
	ray = init_ray(hitrec.hitpoint, ray_direction);
	hitrec2 = ray_collisions(data, ray);
	if (hitrec2.hit)
		hitrec.material.color = vec_mult(data->alight.material.bright, hitrec.material.color);
	else
	{
		bright = dot_product(hitrec.normal, ray_direction) * data->light.material.bright;
		if (bright < data->alight.material.bright)
			bright = data->alight.material.bright;
		hitrec.material.color = vec_mult(bright, hitrec.material.color);
	}
	return (hitrec);
}
