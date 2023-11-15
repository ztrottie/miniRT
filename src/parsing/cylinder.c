#include "../../include/parsing.h"

static void	parse_pos(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[1], ',');
	if (!splitted)
		map_error("bad split!");
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
	printf("cy\n");
	if (!splitted[0] || !splitted[1] || !splitted[2] || !splitted[3] || !splitted[4] || !splitted[5])
		map_error("Missing arguments");
	if (ft_strncmp(splitted[0], "cy", 2) == 0)
	{
		printf("cy2: %s\n", splitted[2]);
		if (splitted[1] && count_char(splitted[1], ',') == 2)
			parse_pos(splitted, &data->objs[i]);
		if (splitted[2] && count_char(splitted[2], ',') == 2)
			parse_vec(splitted, &data->objs[i]);
		data->objs[i].radius = ft_atof(splitted[3]) / 2;
		data->objs[i].height = ft_atof(splitted[4]);
		if (splitted[5] && check_rgb(ft_atoi(splitted[5])) && count_char(splitted[5], ',') == 2 && count_char(splitted[5], '.') == 0)
			parse_color(splitted, &data->objs[i]);
		data->objs[i].intersect_function = &hit_cylinder;
		ft_x2free((void**)splitted);
	}
}
