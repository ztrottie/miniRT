#include "../../include/parsing.h"

char	**split_line(t_data *data)
{
	char	**map;

	map = split_get_next_line(data->fd, ' ');
	return (map);
}
