#include "../../include/parsing.h"

static void	parse_pos(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[1], ',');
	obj->center.x = ft_atof(splitted[0]);
	obj->center.y = ft_atof(splitted[1]);
	obj->center.z = ft_atof(splitted[2]);
	ft_x2free((void **)splitted);
	printf("pk\n");
}

static void	parse_vec(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[2], ',');

	obj->normal.x = ft_atof(splitted[0]);
	obj->normal.y = ft_atof(splitted[1]);
	obj->normal.z = ft_atof(splitted[2]);
	obj->normal = normalize(obj->normal);
	ft_x2free((void **)splitted);
}

static void	parse_color(char **map, t_objs *obj)
{
	char	**splitted;

	splitted = ft_split(map[3], ',');

	obj->material.color.x = ft_atoi(splitted[0]);
	obj->material.color.y = ft_atoi(splitted[1]);	
	obj->material.color.z = ft_atoi(splitted[2]);
	obj->material.color = normalize(obj->material.color);
	ft_x2free((void **)splitted);

}

void	plane_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (!splitted)
		map_error("bad split!");
	printf("pl\n");
	if (ft_strncmp(splitted[0], "pl", 2) == 0)
	{
		if (splitted[1] && count_char(splitted[1], ',') == 2)
			parse_pos(splitted, &data->objs[i]);
		printf("ah ouin\n");
		if (count_char(splitted[2], ',') == 2)
			parse_vec(splitted, &data->objs[i]);
		if (check_rgb(ft_atoi(splitted[3])) && count_char(splitted[3], ',') == 2 && count_char(splitted[3], '.') == 0)
			parse_color(splitted, &data->objs[i]);
		data->objs[i].intersect_function = &hit_plane;
	}
}
