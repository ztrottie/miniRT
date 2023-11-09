#include "../../include/parsing.h"

void	run_map(t_data *data, char *av)
{
	int	i;

	i = 0;
	read_map(data, av);
	while (i < map_len(av))
	{
		check_map(data , i);
		i++;
	}
}
