#include "../../include/parsing.h"

int	check_file_extention(char *av)
{
	av = ft_strrchr(av, '.');
	if (!av)
		return (0);
	else
		return (ft_strncmp(av, ".rt", 3), 1);
}

int	open_map(t_data *data, char *arg)
{
	printf("allo\n");
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
