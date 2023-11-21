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
			if (data->map[i] && ft_strncmp(data->map[i], data->type[j], 2) == 0)
				count++;
			j++;
		}
		i++;
	}
	data->nb_objs = count;
}

void	count_not_objs(t_data *data)
{
	if (data->count_light != 1 || data->count_cam != 1
		|| data->count_alight != 1)
		map_error("Cannot have more than one cam light or ambient light");
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
	count_not_objs(data);
	ft_x2free((void **)data->map);
}
