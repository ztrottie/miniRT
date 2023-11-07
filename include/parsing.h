#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"
# include "maths.h"
# include <fcntl.h>

# define CAM 		C
# define LIGHT 		L
# define ALIGHT		A
# define SPHERE 	sp
# define CYLINDER	cy
# define PLANE 		pl
# define MAP		"Scenes/testScene.rt"

int				map_len(char *av);
int				map_error(char *message);
//int				line_len(char **splitted);
void			read_map(t_data *data, char *av);
int				open_map(char *path);
void			check_map(t_data *data, int i);
void			run_map(t_data *data, char *av);
int				count_char(char *str, char target);
int				check_rgb(int nb);
void			sphere_verif(t_data *data, char **map, int i);
void			cylinder_verif(t_data *data, char **map, int i);




#endif