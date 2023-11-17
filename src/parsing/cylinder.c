#include "../../include/parsing.h"

static void	parse_pos(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[1], ',');
	if (!splitted)
		map_error("bad split!");
	if (splitted && (!splitted[0] || !splitted[1] || !splitted[2]))
		map_error("must be at least 0, cannot be empty");
	obj->center.x = ft_atof(splitted[0]);
	obj->center.y = ft_atof(splitted[1]);
	obj->center.z = ft_atof(splitted[2]);
	ft_x2free((void **)splitted);
}

static void	parse_vec(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[2], ',');
	if (!splitted)
		map_error("bad split!");
	if (splitted && (!splitted[0] || !splitted[1] || !splitted[2]))
		map_error("must be at least 0, cannot be empty");
	obj->normal.x = ft_atof(splitted[0]);
	obj->normal.y = ft_atof(splitted[1]);
	obj->normal.z = ft_atof(splitted[2]);
	obj->normal = normalize(obj->normal);
	ft_x2free((void **)splitted);
}

static void	parse_color(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[5], ',');
	if (!splitted)
		map_error("bad split!");
	if (splitted && (!splitted[0] || !splitted[1] || !splitted[2]))
		map_error("must be at least 0, cannot be empty");
	if (ft_strlen(splitted[0]) > 3 || ft_strlen(splitted[1]) > 3 || ft_strlen(splitted[2]) > 4)
		map_error("Not rgb value, most be max 3 digits in cylinder");
	check_rgb(ft_atoi(splitted[0]));
	check_rgb(ft_atoi(splitted[1]));
	check_rgb(ft_atoi(splitted[2]));
	obj->material.color.x = ft_atoi(splitted[0]);
	obj->material.color.y = ft_atoi(splitted[1]);
	obj->material.color.z = ft_atoi(splitted[2]);
	obj->material.color = normalize(obj->material.color);
	ft_x2free((void **)splitted);
}

void	cylinder_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (!splitted)
		map_error("bad split!");
	if (!splitted[0] || !splitted[1] || !splitted[2] || !splitted[3] || !splitted[4] || !splitted[5] || splitted[6])
		map_error("Missing arguments need 5 arguments for cylinder");
	if (ft_strncmp(splitted[0], "cy", 3) == 0)
	{
		if (splitted[1] && count_char(splitted[1], ',') == 2)
			parse_pos(splitted, &data->objs[data->index]);
		if (splitted[2] && count_char(splitted[2], ',') == 2)
			parse_vec(splitted, &data->objs[data->index]);
		data->objs[data->index].radius = ft_atof(splitted[3]) / 2;
		data->objs[data->index].height = ft_atof(splitted[4]);
		if (splitted[5] && count_char(splitted[5], ',') == 2 && count_char(splitted[5], '.') == 0)
			parse_color(splitted, &data->objs[data->index]);
		data->objs[data->index].intersect_function = &hit_cylinder;
		data->index++;
	}
	ft_x2free((void**)splitted);
}
