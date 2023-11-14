#include "../../include/parsing.h"

static void	parse_pos(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[1], ',');
	obj->center.x = ft_atof(splitted[0]);
	obj->center.y = ft_atof(splitted[1]);
	obj->center.z = ft_atof(splitted[2]);
	ft_x2free((void **)splitted);
}

void	parse_color(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[3], ',');
	obj->material.color.x = ft_atoi(splitted[0]);
	obj->material.color.y = ft_atoi(splitted[1]);
	obj->material.color.z = ft_atoi(splitted[2]);
	obj->material.color = normalize(obj->material.color);
	ft_x2free((void **)splitted);
}
void	sphere_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (!splitted)
		map_error("bad split!");
	printf("sp\n");
	if (ft_strncmp(splitted[0], "sp", 2) == 0)
	{
		if (!splitted || !splitted[0] || !splitted[1])
			map_error("Invalid map");
		if (count_char(splitted[1], ',') == 2)
			parse_pos(splitted, &data->objs[i]);
		if (count_char(splitted[2], ',') == 0)
			data->objs[i].radius = ft_atof(splitted[2]) / 2;
		if (count_char(splitted[3], ',') == 2 && count_char(splitted[3], '.') == 0 && check_rgb(ft_atoi(splitted[3])))
			parse_color(splitted, &data->objs[i]);
		data->objs[i].intersect_function = &hit_sphere;
		ft_x2free((void**)splitted);
	}
}
