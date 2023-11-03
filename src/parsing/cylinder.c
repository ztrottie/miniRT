#include "../../include/parsing.h"

static void	parse_pos(char **map, t_cylinder *cy)
{
	char	**splitted;

	splitted = ft_split(map[1], ',');

	cy->center.x = ft_atof(splitted[0]);
	cy->center.y = ft_atof(splitted[1]);
	cy->center.z = ft_atof(splitted[2]);
}

void	parse_vec(char **map, t_cylinder *cy)
{
	char	**splitted;

	splitted = ft_split(map[2], ',');
	cy->vec->x = ft_atof(splitted[0]);
	cy->vec->y = ft_atof(splitted[1]);
	cy->vec->z = ft_atof(splitted[2]);
}

void	parse_color(char **map, t_cylinder *cy)
{
	char	**splitted;

	splitted = ft_split(map[3], ',');
	cy->material.color.x = ft_atof(splitted[0]);
	cy->material.color.y = ft_atof(splitted[1]);
	cy->material.color.z = ft_atof(splitted[2]);
}

void	cylinder_verif(t_cylinder *cy, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (count_char(splitted[1], ',') == 2)
		parse_pos(splitted, cy);
	ft_printf("CBT\n");
	if (count_char(splitted[2], ',') == 2)
		parse_vec(splitted, cy);
	cy->radius = ft_atoi(splitted[3]) / 2;
	cy->height = ft_atof(splitted[4]);
	if (check_rgb(ft_atoi(splitted[5])) && count_char(splitted[5], ',') == 0 && count_char(splitted[5], '.'))
		parse_color(splitted, cy);
}
