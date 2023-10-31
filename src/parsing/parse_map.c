#include "../../include/parsing.h"

void	run_map(char **map, t_data *data)
{
	int	i;

	i = 0;
	if (!map || !*map)
		map_error("Something went wrong with the map!");
	while (map && map[i])
	{
		check_map(map, data , i);
		i++;
	}
}
