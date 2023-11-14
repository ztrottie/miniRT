#include "../../include/parsing.h"

static void	parse_pos(char **map, t_data *data)
{
	char	**splitted;

	splitted = ft_split(map[1], ',');
	if (!splitted)
		map_error("bad split!");
	data->cam.x = ft_atof(splitted[0]);
	data->cam.y = ft_atof(splitted[1]);
	data->cam.z = ft_atof(splitted[2]);
	ft_x2free((void **)splitted);
}


void	camera_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (!splitted)
		map_error("bad split!");
	printf("C\n");
	if (ft_strncmp(splitted[0], "C", 1) == 0)
	{
		if (count_char(splitted[1], ',') == 2)
			parse_pos(map, data);
		data->fov = ft_atoi(splitted[2]); //need to check range
	}
	ft_x2free((void **)splitted);
}

