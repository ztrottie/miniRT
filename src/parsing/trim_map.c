#include "../include/parsing.h"

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
	int		i;
	char	*temp;
	char	**splited_map;

	i = 0;
	temp = read_map(data);
	while (temp)
	{
		splited_map = ft_split(temp, 32);
		i++;
	}
	return (splited_map);
}
