#include "../../include/parsing.h"
/// @brief print error with a new line for the costum message
/// @param message the error message to display
int	map_error(char *message)
{
	ft_printf("Error\n");
	ft_printf("%s\n", message);
	return (1);
}

int	check_if_rt(char *av)
{
	av = ft_strrchr(av, '.');
	if (!av)
		return (0);
	else
		return (ft_strncmp(av, ".ber", 5));
}
