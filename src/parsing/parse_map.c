#include "../../include/parsing.h"

void	run_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		check_map(map);
		i++;
	}
}
