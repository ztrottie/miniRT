#include "../../include/renderer.h"

t_hitrec	ray_collisions(t_data *data, t_ray ray, int t_max)
{
	int			i;
	t_hitrec	hitrec;
	t_hitrec	closest_hit;

	i = 0;
	closest_hit.t = INFINITY;
	closest_hit.hit = false;
	while (i < data->nb_objs)
	{
		hitrec = data->objs[i].intersect_function(data->objs[i], ray, t_max);
		if (hitrec.hit && hitrec.t < closest_hit.t)
			closest_hit = hitrec;
		i++;
	}
	return (closest_hit);
}
