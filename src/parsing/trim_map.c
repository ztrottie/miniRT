#include "../include/parsing.h"

int	skip_white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ft_isspace(str[i]))
		++i;
	return (i);
}


char	**split_map(char **str)
{
	int		i;
	int		j;
	char	**splited_map;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = skip_white_space(str[i]);
		splited_map = ft_split(str[i], 32);
		i++;
	}
	return (splited_map);
}
