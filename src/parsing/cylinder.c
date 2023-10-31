#include "../../include/parsing.h"

static void	parse_pos(char **map, t_cylinder *cy, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ',');
	cy->center.x = ft_atof(splitted[1]);
	cy->center.y = ft_atof(splitted[2]);
	cy->center.z = ft_atof(splitted[3]);
	ft_x2free((void **)splitted);
}

void	parse_vec(char **map, t_cylinder *cy, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ',');
	cy->vec->x = ft_atof(splitted[1]);
	cy->vec->y = ft_atof(splitted[2]);
	cy->vec->z = ft_atof(splitted[3]);
	ft_x2free((void **)splitted);
}

void	parse_color(char **map, t_cylinder *cy, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ',');
	cy->material.color.x = ft_atof(splitted[1]);
	cy->material.color.y = ft_atof(splitted[2]);
	cy->material.color.z = ft_atof(splitted[3]);
	ft_x2free((void **)splitted);
}

void	cylinder_verif(t_cylinder *cy, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (count_char(splitted[1], ',') == 2)
		parse_pos(map, cy, i);
	if (count_char(splitted[2], ',') == 2)
		parse_vec(map, cy, i);
	cy->radius = ft_atoi(splitted[3]) / 2;
	cy->height = ft_atof(splitted[4]);
	if (check_rgb(ft_atoi(splitted[5])) && count_char(splitted[5], ',') == 0 && count_char(splitted[5], '.'))
		parse_color(map, cy, i);
}
