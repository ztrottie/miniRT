#include "../../include/run.h"

void	init_viewport(t_data *data)
{
	int 		deg;
	t_vec		dir;
	t_viewport	*vp;

	vp = &data->vp;
	deg = -90;
	vp->vp_height = 2.0; 
	vp->vp_width = vp->vp_height * (((double)WIDTH / data->img_height));
	vp->focal_len = (vp->vp_width / 2) / tan(data->fov / 2);
}
