#include "../../include/parsing.h"

void	obj_increment(t_data *data)
{
	size_t	j;
	int		i;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (data->map[i])
	{
		j = 0;
		while (j < NB_OBJECT)
		{
			if (data->map[i] && data->type[j] && ft_strncmp(data->map[i], data->type[j], 2) == 0)
				count++;
			j++;
		}
		i++;
	}
	data->nb_objs = count;
}

/// @brief read the file and dup each line into data.map wich is a double array
/// @param data struct will all the data
void	read_map(t_data *data, char *av)
{
	char	*line;
	int		i;
	int		count;
	int		fd;

	i = 0;
	fd = open_map(av);
	count = map_len(av);
	line = get_next_line(fd);
	data->map = ft_calloc(sizeof(char *), (count + 1));
	while (i < count)
	{
		data->map[i] = ft_strdup(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

/// @brief will check each component if its in the map
/// @param map the map you need to check
void	check_map(t_data *data, int i)
{
	if (ft_x2strlen(data->map) == 0)
		map_error("Your map is invalid dumbass🤡");
	else if (ft_strncmp(data->map[i], "sp ", 3) == 0)
	{
		sphere_verif(data, data->map, i);
	}
	else if (ft_strncmp(data->map[i], "cy ", 3) == 0)
	{
		cylinder_verif(data, data->map, i);
	}
	else if (ft_strncmp(data->map[i], "pl ", 3) == 0)
	{
		plane_verif(data, data->map, i);
	}
	else if (ft_strncmp(data->map[i], "A ", 2) == 0)
	{
		ambient_verif(data, data->map, i);
		printf("tu segfault ou\n");

	}
	else if (ft_strncmp(data->map[i], "L ", 2) == 0)
	{
		light_verif(data, data->map, i);

	}
	else if (ft_strncmp(data->map[i], "C ", 2) == 0)
	{
		camera_verif(data, data->map, i);

	}
	else
		map_error("fix your shit bozo🧂");
}
