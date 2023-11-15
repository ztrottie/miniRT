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

static void	parse_vec(char **map, t_data *data)
{
	char	**splitted;

	splitted = ft_split(map[2], ',');
	if (!splitted)
		map_error("bad split!");
	data->cam_dir.x = ft_atof(splitted[0]);
	data->cam_dir.y = ft_atof(splitted[1]);
	data->cam_dir.z = ft_atof(splitted[2]);
	data->cam_dir = normalize(data->cam_dir);
	ft_x2free((void **)splitted);
}

void	camera_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (!splitted)
		map_error("bad split!");
	printf("C\n");
	if (!splitted[0] || !splitted[1] || !splitted[2] || !splitted[3])
		map_error("Missing arguments");
	if (ft_strncmp(splitted[0], "C", 1) == 0)
	{
		if (count_char(splitted[1], ',') == 2)
			parse_pos(splitted, data);
		if (count_char(splitted[2], ',') == 2)
			parse_vec(splitted, data);
		if (ft_atoi(splitted[3]) >= 0 && ft_atoi(splitted[3]) <= 180)
			data->fov = ft_atoi(splitted[3]);
	}
	ft_x2free((void **)splitted);
}
