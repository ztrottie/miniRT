#include "../../include/parsing.h"

int	count_char(char *str, char target)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == target)
			count++;
		i++;
	}
	return (count);
}

int	check_rgb(int nb)
{
	if (nb >= 0 && nb <= 255)
		return (1);
	else
	{
		map_error("Not rgb value");
		return (0);
	}
}
