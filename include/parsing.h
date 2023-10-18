#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"
# include <fcntl.h>

# define CAM 		C
# define LIGHT 		L
# define ALIGHT		A
# define SPHERE 	sp
# define CYLINDER	cy
# define PLANE 		pl

void			split_map(t_data *data);
int				map_error(char *message);
int				line_len(char **splitted);
int				check_if_rt(char *av);


#endif