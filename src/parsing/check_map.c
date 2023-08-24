#include "../include/parsing.h"

int	check_file_extention(char *av)
{
	av = ft_strrchr(av, '.');
	(!av)
		return (0);
	else
		return (ft_strncmp(av, ".rt", 3));
}

int	check_component(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], 'A', 2) == 0)
			i++;
		if (ft_strncmp(str[i], 'L', 2) == 0)
			i++;
		if (ft_strncmp(str[i], 'C', 2) == 0)
			i++;
		if (ft_strncmp(str[i], "sp", 3) == 0)
			i++;
		if (ft_strncmp(str[i], "pl", 3) == 0)
			i++;
		if (ft_strncmp(str[i], "cy", 3) == 0)
			i++;
		i++;
	}
	return (VALID);
}
