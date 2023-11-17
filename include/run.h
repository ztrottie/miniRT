#ifndef RUN_H
# define RUN_H

# include "minirt.h"
# include "maths.h"
# include <math.h>
# include "renderer.h"
# include "parsing.h"

void	movement_handler(mlx_key_data_t keydata, void *param);
void	init_viewport(t_data *data);
void	init_rotations(t_data *data);
void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void* param);

#endif