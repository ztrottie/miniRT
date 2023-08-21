#include "../../include/minirt.h"

int	check_file_extention(char *av)
{
	av = ft_strrchr(av, '.');
	(!av)
		return (0);
	else
		return (ft_strncmp(av, ".rt", 3));
}

int	check_if_valid(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			
		}
	}
}
