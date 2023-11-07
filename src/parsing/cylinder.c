#include "../../include/parsing.h"

static void	parse_pos(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[1], ',');

	obj->center.x = ft_atof(splitted[0]);
	obj->center.y = ft_atof(splitted[1]);
	obj->center.z = ft_atof(splitted[2]);
}

void	parse_vec(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[2], ',');
	obj->normal.x = ft_atof(splitted[0]);
	obj->normal.y = ft_atof(splitted[1]);
	obj->normal.z = ft_atof(splitted[2]);
}

void	parse_color(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[3], ',');
	obj->material.color.x = ft_atof(splitted[0]);
	obj->material.color.y = ft_atof(splitted[1]);
	obj->material.color.z = ft_atof(splitted[2]);
}

void	cylinder_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (count_char(splitted[1], ',') == 2)
		parse_pos(splitted, data->objs);
	if (count_char(splitted[2], ',') == 2)
		parse_vec(splitted, data->objs);
	data->objs->radius = ft_atoi(splitted[3]) / 2;
	data->objs->height = ft_atof(splitted[4]);
	if (check_rgb(ft_atoi(splitted[5])) && count_char(splitted[5], ',') == 0 && count_char(splitted[5], '.'))
		parse_color(splitted, data->objs);
	//data->objs[i].intersect_function = &hit_cylinder;
}
