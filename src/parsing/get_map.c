#include "../../include/parsing.h"

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
	else if (ft_strncmp(data->map[0], "sp ", 3) == 0)
		sphere_verif(data, data->map, i);
	else if (ft_strncmp(data->map[0], "cy ", 3) == 0)
		cylinder_verif(data, data->map, i);
	else
		map_error("fix your shit bozo🧂");
}
