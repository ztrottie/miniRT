#include "../../../include/minirt.h"

int	skip_white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ft_isspace(str[i]))
		++i;
	return (i);
}

int	trim_map(char **str)
{
	int	i;

	i = skip_white_space(str[i]);
	while (str[i])
	{
		i++;
	}
	return (VALID);
}
