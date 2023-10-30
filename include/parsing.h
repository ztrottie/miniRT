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
# define MAP		"Scenes/testScene.rt"

int				map_len();
int				map_error(char *message);
int				line_len(char **splitted);
int				check_if_rt(char *av);
void			read_map(t_data *data);
int				open_map(char *path);
void			check_map(char **map, t_data *data, int i);
void			run_map(char **map, t_data *data);
int				count_char(char *str, char target);
int				check_rgb(int nb);
void			sphere_verif(t_sphere *sphere, char **map, int i);



#endif