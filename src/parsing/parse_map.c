#include "../../include/parsing.h"

void	run_map(char **map, t_data *data)
{
	int	i;

	i = 0;
	while (map[i])
	{
		check_map(map, data , i);
		i++;
	}
}
