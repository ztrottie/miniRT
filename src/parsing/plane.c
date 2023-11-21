#include "../../include/parsing.h"

void	plane_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (!splitted)
		map_error("bad split!");
	if (!splitted[0] || !splitted[1] || !splitted[2] || !splitted[3] || splitted[4])
		map_error("Missing arguments need 4 arguments for plane");
	if (ft_strncmp(splitted[0], "pl", 2) == 0)
	{
		if (splitted[1] && count_char(splitted[1], ',') == 2)
			parse_pos(splitted, &data->objs[data->index]);
		else
			map_error("Invalid patern for plane position");
		if (splitted[2] && count_char(splitted[2], ',') == 2)
			parse_vec(splitted, &data->objs[data->index]);
		else
			map_error("Invalid patern for plane vectors");
		if (splitted[3] && count_char(splitted[3], ',') == 2 && count_char(splitted[3], '.') == 0)
		{
			parse_color(splitted, &data->objs[data->index]);
			printf("pl\n");
		}
		else
			map_error("Invalid patern for plane rgb");
		data->objs[data->index].intersect_function = &hit_plane;
	data->index++;
		ft_x2free((void **)splitted);
	}
}
