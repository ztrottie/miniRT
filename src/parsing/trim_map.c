#include "../../../include/minirt.h"

int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ft_isspace(str[i]))
			i++;
		else
			return (i);
		i++;
	}
	return (i);
}

int	trim_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (skip_space(str[j]) < 0)
			return (INVALID);
		i++;
	}
	return (VALID);
}
