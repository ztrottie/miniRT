#include "../../include/parsing.h"

void	run_map(t_data *data, char *av)
{
	int	i;
	int	count;

	i = 0;
	read_map(data, av);
	data->map = reset(NULL, data->map);
	count = ft_x2strlen(data->map);
	obj_increment(data);
	data->objs = ft_calloc(data->nb_objs, sizeof(t_objs));
	if (!data->objs)
		map_error("Malloc fail");
	while (i < count)
	{
		check_map(data , i);
		i++;
	}
}
