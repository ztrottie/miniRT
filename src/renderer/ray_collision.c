#include "../../include/renderer.h"

t_hitrec	sphere_collisions(t_data *data, t_ray ray)
{
	int			i;
	t_hitrec	hitrec;
	t_hitrec	closest_hit;
	t_sphere	*sphere;;

	i = 0;
	closest_hit.t = INT_MAX;
	if (data->objs.sphere)
	{
		sphere = data->objs.sphere;
		while (i < data->nb_sphere)
		{
			hitrec = hit_sphere(sphere[i], ray, T_MAX, 0);
			if (hitrec.hit && hitrec.t < closest_hit.t)
			{
				closest_hit = hitrec;
			}
			i++;
		}
	}
	return (closest_hit);
}

t_hitrec	ray_collisions(t_data *data, t_ray ray)
{
	t_hitrec closest_hit;

	closest_hit = sphere_collisions(data, ray);
	return (closest_hit);
}
