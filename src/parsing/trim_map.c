#include "../../include/parsing.h"

int	skip_white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ft_isspace(str[i]))
		++i;
	return (i);
}

char	**split_map(t_data *data)
{
	char	**map_split = NULL;
	char	*map;

	map = read_map(data);
	if (map)
		map_split = ft_split(map, 32);
	if (!map_split)
		return(INVALID);
	printf("%s\n", map);
	return (map_split);
}	
