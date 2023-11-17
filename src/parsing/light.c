#include "../../include/parsing.h"

static void	parse_pos(char **map, t_light *light)
{
	char	**splitted;

	splitted = ft_split(map[1], ',');
	if (!splitted)
		map_error("bad split!");
	light->center.x = ft_atof(splitted[0]);
	light->center.y = ft_atof(splitted[1]);
	light->center.z = ft_atof(splitted[2]);
	ft_x2free((void **)splitted);
}

void	light_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (!splitted[0] || !splitted[1] || !splitted[2])
		map_error("Missing arguments");
	if (ft_strncmp(splitted[0], "L", 2) == 0)
	{
		if (splitted[1] && count_char(splitted[1], ',') == 2)
			parse_pos(splitted, &data->light);
		if (splitted[2] && check_brightness(ft_atof(splitted[2])))
			data->light.material.bright = ft_atof(splitted[2]);
		ft_x2free((void **)splitted);
	}
}