#include "../../include/parsing.h"

void	parse_color(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[3], ',');
	if (splitted && (!splitted[0] || !splitted[1] || !splitted[2]))
		map_error("Cannot be empty");
	if (ft_strlen(splitted[0]) > 3 || ft_strlen(splitted[1]) > 3 || ft_strlen(splitted[2]) > 4)
		map_error("Not rgb value, most be max 3 digits in sphere");
	check_rgb(ft_atoi(splitted[0]));
	check_rgb(ft_atoi(splitted[1]));
	check_rgb(ft_atoi(splitted[2]));
	obj->material.color.x = ft_atoi(splitted[0]);
	obj->material.color.y = ft_atoi(splitted[1]);
	obj->material.color.z = ft_atoi(splitted[2]);
	obj->material.color = normalize(obj->material.color);
	ft_x2free((void **)splitted);
}

void	parse_vec(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[2], ',');
	if (splitted && (!splitted[0] || !splitted[1] || !splitted[2]))
		map_error("t'est gay");	
	obj->normal.x = ft_atof(splitted[0]);
	obj->normal.y = ft_atof(splitted[1]);
	obj->normal.z = ft_atof(splitted[2]);
	obj->normal = normalize(obj->normal);
	ft_x2free((void **)splitted);
}

void	parse_pos(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[1], ',');
	if (splitted && (!splitted[0] || !splitted[1] || !splitted[2]))
		map_error("t'est gay");
	obj->center.x = ft_atof(splitted[0]);
	obj->center.y = ft_atof(splitted[1]);
	obj->center.z = ft_atof(splitted[2]);
	ft_x2free((void **)splitted);
}
