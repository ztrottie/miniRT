#include "../../include/parsing.h"

static void	parse_pos(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[1], ',');

	obj->center.x = ft_atof(splitted[0]);
	obj->center.y = ft_atof(splitted[1]);
	obj->center.z = ft_atof(splitted[2]);
}

static void	parse_vec(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[2], ',');
	obj->normal.x = ft_atof(splitted[0]);
	obj->normal.y = ft_atof(splitted[1]);
	obj->normal.z = ft_atof(splitted[2]);
	obj->normal = normalize(obj->normal);
}

static void	parse_color(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[3], ',');
	obj->material.color.x = ft_atof(splitted[0]);
	obj->material.color.y = ft_atof(splitted[1]);
	obj->material.color.z = ft_atof(splitted[2]);
}

void	plane_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	printf("pl\n");
	if (ft_strncmp(splitted[0], "pl", 2) == 0)
	{
		if (splitted[1])
			parse_pos(splitted, &data->objs[i]);
		if (count_char(splitted[2], ',') == 2)
			parse_vec(splitted, &data->objs[i]);
		if (check_rgb(ft_atof(splitted[3])) && count_char(splitted[3], ',') == 2 && count_char(splitted[3], '.') == 0)
			parse_color(splitted, &data->objs[i]);
		data->objs[i].intersect_function = &hit_cylinder;
	}
}
