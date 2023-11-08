#include "../../include/parsing.h"

/// @brief simply check if the number given is between rgb range
/// @param nb the rgb value
/// @return 1 if correct and 0 if there is an error
int	check_rgb(int nb)
{
	if (nb >= 0 && nb <= 255)
		return (1);
	else
		return (map_error("Not rgb value"));
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

/// @brief count the number of line with get_next_line
/// @return the number of lines
int	map_len(char *av)
{
	int		count;
	int		fd;

	fd = open_map(av);
	count = count_next_line(fd);
	close(fd);
	return (count);
}
