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

int			open_map(t_data *data, char *arg);
int			check_file_extention(char *av);
char		*read_map(t_data *data);
char		**split_map(t_data *data);

#endif