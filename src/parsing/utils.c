#include "../../include/parsing.h"

int	check_brightness(double brightness)
{
	if (brightness >= 0.0 && brightness <= 1.0)
		return (1);
	else
		return (map_error("brightness must be in range [0.0,1.0]"));
}

char	**reset(char **env, char **cpy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	env = ft_calloc(ft_x2strlen(cpy) + 1, sizeof(char *));
	while (cpy[j])
	{
		if (ft_strcmp(cpy[j], "\n"))
		{
			env[i] = ft_strdup(cpy[j]);
			i++;
		}
		j++;
	}
	ft_x2free((void **)cpy);
	return (env);
}

/// @brief simply check if the number given is between rgb range
/// @param nb the rgb value
/// @return 1 if correct and 0 if there is an error
int	check_rgb(int nb)
{
	if (nb >= 0 && nb <= 255)
		return (1);
	else
		return (map_error("RGB must be between 0-255"));
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

void	find_coma(char **line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i])
	{
		j = 0;
		while (line[i][j] && line[i][j] != ',' && line[i][j] != '.')
			j++;
		if ((line[i][j] == ',' && line[i][j - 1] == ' ') 
			|| (line[i][j] == ',' && line[i][j + 1] == ' '))
			map_error("No space allowed before or after coma");
		if ((line[i][j] == '.' && line[i][j - 1] == ' ') 
			|| (line[i][j] == '.' && line[i][j + 1] == ' '))
			map_error("No space allowed before or after dot");
		i++;
	}
}
