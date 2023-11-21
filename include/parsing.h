#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"
# include "renderer.h"
# include "maths.h"
# include <fcntl.h>

# define CAM 		C
# define LIGHT 		L
# define ALIGHT		A
# define SPHERE 	sp
# define CYLINDER	cy
# define PLANE 		pl
# define MAP		"Scenes/testScene.rt"

int				map_error(char *message);
int 			map_len(char *av);
void			read_map(t_data *data, char *av);
int				open_map(char *path);
void			check_map(t_data *data, int i);
void			run_map(t_data *data, char *av);
int				count_char(char *str, char target);
int				check_rgb(int nb);
void			sphere_verif(t_data *data, char **map, int i);
void			cylinder_verif(t_data *data, char **map, int i);
void			plane_verif(t_data *data, char **map, int i);
void			ambient_verif(t_data *data, char **map, int i);
void			light_verif(t_data *data, char **map, int i);
void			camera_verif(t_data *data, char **map, int i);

char			**reset(char **env, char **env_cpy);
void			obj_increment(t_data *data);
int				check_brightness(double brightness);
void			find_coma(char **line);
bool			check_if_obj(t_data *data, char *line);
void			count_not_objs(t_data *data);

void	parse_color(char **map, t_objs *obj);
void	parse_vec(char **map, t_objs *obj);
void	parse_pos(char **map, t_objs *obj);

#endif