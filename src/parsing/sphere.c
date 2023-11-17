#include "../../include/parsing.h"

static void	parse_pos(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[1], ',');
	if (splitted && (!splitted[0] || !splitted[1] || !splitted[2]))
		map_error("Must be at least 0");
	obj->center.x = ft_atof(splitted[0]);
	obj->center.y = ft_atof(splitted[1]);
	obj->center.z = ft_atof(splitted[2]);
	ft_x2free((void **)splitted);
}

void	parse_color(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[3], ',');
	if (splitted && (!splitted[0] || !splitted[1] || !splitted[2]))
		map_error("Must be at least 0");
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

void	sphere_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (!splitted)
		map_error("bad split!");
	if (!splitted[0] || !splitted[1] || !splitted[2] || !splitted[3] || splitted[4])
		map_error("Missing arguments need 4 arguments for sphere");
	if (ft_strncmp(splitted[0], "sp", 3) == 0)
	{
		if (count_char(splitted[1], ',') == 2)
			parse_pos(splitted, &data->objs[data->index]);
		else
			map_error("Invalid patern for sphere position");
		if (count_char(splitted[2], ',') == 0)
			data->objs[data->index].radius = ft_atof(splitted[2]) / 2;
		else
			map_error("Invalid patern for sphere radius");
		if (count_char(splitted[3], ',') == 2 && count_char(splitted[3], '.') == 0)
			parse_color(splitted, &data->objs[data->index]);
		else
			map_error("Invalid patern for sphere rgb");
		data->objs[data->index].intersect_function = &hit_sphere;
		data->index++;
		ft_x2free((void**)splitted);
	}
}
