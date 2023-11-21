#include "../../include/run.h"
#include "../../include/renderer.h"

void	mouse_hook(mouse_key_t button, action_t action, \
modifier_key_t mods, void *param)
{
	t_data		*data;
	t_rend		rend;

	data = param;
	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		mlx_get_mouse_pos(data->mlx, &rend.i, &rend.j);
		ray_gen(data, &rend);
		ft_bzero(&data->selected, sizeof(t_selected));
		data->selected.objs = ray_collisions(data, rend.ray, T_MAX).inst;
	}
}
