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

char	**split_line(t_data *data);
void	map_error(char *message);
int		line_len(char **splitted);
void	check_map(char **map);


#endif