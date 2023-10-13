#include "../../include/parsing.h"

char	**split_line(t_data *data)
{
	char	**map;

	map = split_get_next_line(data->fd, ' ');
	return (map);
}

int	line_len(char **splitted)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

int	check_map(t_data *data)
{

}
