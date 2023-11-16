#include "../../include/parsing.h"

void	obj_increment(t_data *data)
{
	size_t	j;
	int		i;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (data->map && data->map[i])
	{
		j = 0;
		while (j < NB_OBJECT)
		{
			if (data->map[i] && data->type[j] && ft_strncmp(data->map[i], data->type[j], 2) == 0)
			{
				count++;
			}
			j++;
		}
		i++;
	}
	data->nb_objs = count;
}

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
		check_map(data, i);
		i++;
	}
}
