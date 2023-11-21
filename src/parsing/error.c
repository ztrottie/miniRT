#include "../../include/parsing.h"
/// @brief print error with a new line for the costum message and exit with -1
/// @param message the error message to display
int	map_error(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s", message);
	ft_printf("\n");
	exit(-1);
}
/// @brief check if av has a .rt at the end
/// @param av the main arguments wich would be a file
/// @return the difference between the av and .ber if 0 then there is a .ber 
static int	check_if_rt(char *av)
{
	av = ft_strrchr(av, '.');
	if (!av)
		return (0);
	else
		return (ft_strncmp(av, ".ber", 5));
}

/// @brief open a file and return an error if necessary
/// @param path the file you wish to open
/// @return the fd so we can use it elsewhere
int	open_map(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		map_error("Could not open the selected map!");
	else if (check_if_rt(path) == 0)
		map_error("Scene must finish with a .rt");
	return (fd);
}

bool	check_if_obj(t_data *data, char *line)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (line[i] != ' ')
	{
		j = 0;
		while (j < NB_OBJECT)
		{
			if (line[i] && ft_strncmp(line, data->type[j], 2) == 0)
				return (true);
			j++;
		}
	}
	return (false);
}
