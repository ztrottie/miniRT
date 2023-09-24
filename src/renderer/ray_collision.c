#include "../../include/renderer.h"

static t_hitrec	sphere_collisions(t_data *data, t_ray ray, double max)
{
	int			i;
	t_hitrec	hitrec;
	t_hitrec	closest_hit;
	t_sphere	*sphere;;

	i = 0;
	closest_hit.t = INFINITY;
	if (data->objs.sphere)
	{
		sphere = data->objs.sphere;
		while (i < data->nb_sphere)
		{
			hitrec = hit_sphere(sphere[i], ray, max, 0);
			if (hitrec.hit && hitrec.t < closest_hit.t)
			{
				closest_hit = hitrec;
			}
			i++;
		}
	}
	return (closest_hit);
}

t_hitrec	ray_collisions(t_data *data, t_ray ray, double max)
{
	t_hitrec closest_hit;

	closest_hit = sphere_collisions(data, ray, max);
	return (closest_hit);
}
