#include "../../include/parsing.h"

/// @brief get the len of a line in a double array
/// @param splitted the splitted map
/// @return the length of the line
int	line_len(char **splitted)
{
	int	i;

	i = 0;
	while(splitted[i])
		i++;
	return (i);
}

/// @brief count the number of line with get_next_line
/// @return the number of lines
int	map_len(void)
{
	char	*gnl;
	int		count;
	int		fd;

	gnl = "yessir miller";
	count = 0;
	fd = open_map(MAP);
	while (gnl)
	{
		gnl = get_next_line(fd);
		count++;
		ft_free(gnl);
	}
	close(fd);
	return (count);
}

/// @brief read the file and dup each line into data.map wich is a double array
/// @param data struct will all the data
void	read_map(t_data *data)
{
	char	*line;
	int		i;
	int		count;
	int		fd;

	line = NULL;
	i = 0;
	fd = open_map(MAP);
	count = map_len();
	data->map = malloc(sizeof(char *) * (count + 1));
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
void	check_map(char **map, t_data *data, int i)
{
	if (line_len(map) == 0)
		return ;
	else if (line_len(map) > 2)
		map_error("Unknow object in file! Cmon bozo🤡");
	else if (ft_strncmp(map[0], "sp", 2) == 0) //add map[0] + skip_whitespace
		sphere_verif(data->objs.sphere, map, i);
	// else if (ft_strncmp(map[0], "cy", 2) == 0)
	// 	cylinder_verif();
	// else if (ft_strncmp(map[0], "pl", 2) == 0)
	// 	plane_verif();
	// else if (ft_strncmp(map[0], 'C', 1) == 0)
	// 	cam_verif();
	// else if (ft_strncmp(map[0], 'A', 1) == 0)
	// 	ambient_verif();
	// else if (ft_strncmp(map[0], 'L', 1) == 0)
	// 	light_verif();
	else
		map_error("fix your shit bozo🧂");
}
