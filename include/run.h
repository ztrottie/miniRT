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

#endif