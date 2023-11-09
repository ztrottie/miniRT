#include "../../include/parsing.h"

static void	sphere_pos(t_objs *obj, char **splitted)
{
	char	**temp_split;
	temp_split = ft_split(splitted[1], ',');
	if (!temp_split)
		map_error("Invalid map!");
	obj->center.x = ft_atof(temp_split[0]);
	obj->center.y = ft_atof(temp_split[1]);
	obj->center.z = ft_atof(temp_split[2]);
}

static void	sphere_rgb(t_objs *obj, char **splitted)
{
	char	**temp_split;

	temp_split = ft_split(splitted[3], ',');
	if (!temp_split)
		map_error("Invalid map!");
	obj->material.color.x = ft_atoi(temp_split[0]);
	obj->material.color.y = ft_atoi(temp_split[1]);
	obj->material.color.z = ft_atoi(temp_split[2]);
	obj->material.color = normalize(obj->material.color);
}

void	sphere_verif(t_data *data, char **map, int i)
{
	char	**splitted;
	splitted = ft_split(map[i], ' ');
	if (ft_strncmp(splitted[0], "sp", 2) == 0)
	{
		if (!splitted || !splitted[0] || !splitted[1])
			map_error("Invalid map");
		if (count_char(splitted[1], ',') == 2)
			sphere_pos(data->objs, splitted);
		if (count_char(splitted[2], ',') == 0)
			data->objs->radius = ft_atof(splitted[2]) / 2;
		if (count_char(splitted[3], ',') == 2 && count_char(splitted[3], '.') == 0 && check_rgb(ft_atoi(splitted[3])))
			sphere_rgb(data->objs, splitted);
		data->objs[i].intersect_function = &hit_sphere;
	}
}
