#include "../../include/parsing.h"

static void	parse_rgb(char **map, t_alight *alight)
{
	char	**splitted;

	splitted = ft_split(map[2], ',');
	if (!splitted)
		map_error("bad split!");
	alight->material.color.x = ft_atoi(splitted[0]);
	alight->material.color.y = ft_atoi(splitted[1]);
	alight->material.color.z = ft_atoi(splitted[2]);
	alight->material.color = normalize(alight->material.color);
	ft_x2free((void **)splitted);
}

void	ambient_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (!splitted)
		map_error("bad split!");
	printf("A\n");
	if (ft_strncmp(data->map[0], "A", 1) == 0)
	{
		if (check_brightness(ft_atof(splitted[1])))
			data->alight.material.bright = ft_atof(splitted[1]);
		if (check_rgb(ft_atoi(splitted[2])) && count_char(splitted[2], '.') == 0 && count_char(splitted[2], ',') == 2)
			parse_rgb(map, &data->alight);
	}
	ft_x2free((void **)splitted);
}
