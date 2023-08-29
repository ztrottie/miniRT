#include "../include/parsing.h"

int	check_file_extention(char *av)
{
	av = ft_strrchr(av, '.');
	(!av)
		return (0);
	else
		return (ft_strncmp(av, ".rt", 3));
}

int	open_map(t_data *data, char *arg)
{
	data->fd = open(arg, O_RDONLY);
	if (data->fd < 1)
		return (printf("Error\ncannot open map"));
	return (VALID);
}

char	*read_map(t_data *data)
{
	char	*temp;
	char	*new;

	temp = "Yessir miller";
	new = NULL;
	while (temp)
	{
		temp = get_next_line(data->fd);
		new = ft_strjoin(new, temp);
		ft_free(temp);
	}
	close(data->fd);
	return (new);
}

// int	check_component(char **str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (ft_strncmp(str[i], 'A', 2) == 0)
// 			i++;
// 		if (ft_strncmp(str[i], 'L', 2) == 0)
// 			i++;
// 		if (ft_strncmp(str[i], 'C', 2) == 0)
// 			i++;
// 		if (ft_strncmp(str[i], "sp", 3) == 0)
// 			i++;
// 		if (ft_strncmp(str[i], "pl", 3) == 0)
// 			i++;
// 		if (ft_strncmp(str[i], "cy", 3) == 0)
// 			i++;
// 		i++;
// 	}
// 	return (VALID);
// }
