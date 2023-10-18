#include "../../include/parsing.h"

void	ambient_verif(t_alight *alight, char **map)
{
	if (line_len(map) != 4)
		map_error("Incorrect structure");
	alight->material.bright = ft_atof(map[1]);
}
