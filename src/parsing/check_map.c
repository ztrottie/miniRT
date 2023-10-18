#include "../../include/parsing.h"

/// @brief read the file and split on each space
/// @param data struct wich have the map and all the data
/// @return the map but splitted on each space
void	split_map(t_data *data)
{
	char	*new;
	char	*line;
	int		i;

	line = "yessir miller";
	new = NULL;
	i = 0;
	while (line)
	{
		line = get_next_line(data->fd);
		data->map[i] = line;
		printf("%s\n", line);
		ft_free(line);
		i++;
	}
	close(data->fd);
}

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

/// @brief check the map to see if everything is valid
/// @param map the map you need to check
// void	check_map(char **map)
// {
// 	if (line_len(map) == 0)
// 		return ;
// 	else if (line_len(map) > 2)
// 		map_error("Unknow object in file! Cmon bozo🤡");
// 	else if (ft_strncmp(map[0], "cy", 2) == 0)
// 		cylinder_verif();
// 	else if (ft_strncmp(map[0], "pl", 2) == 0)
// 		plane_verif();
// 	else if (ft_strncmp(map[0], "sp", 2) == 0)
// 		sphere_verif();
// 	else if (ft_strncmp(map[0], 'C', 1) == 0)
// 		cam_verif();
// 	else if (ft_strncmp(map[0], 'A', 1) == 0)
// 		ambient_verif();
// 	else if (ft_strncmp(map[0], 'L', 1) == 0)
// 		light_verif();
// 	else
// 		map_error("fix your shit bozo🧂");
// }
