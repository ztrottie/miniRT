#include "../../include/parsing.h"

static void	sphere_pos(t_sphere *sphere, char **splitted)
{
	char	**temp_split;
	temp_split = ft_split(splitted[1], ',');
	sphere->center.x = ft_atof(temp_split[0]);
	sphere->center.y = ft_atof(temp_split[1]);
	sphere->center.z = ft_atof(temp_split[2]);
}

static void	sphere_rgb(t_sphere *sphere, char **splitted)
{
	char	**temp_split;

	temp_split = ft_split(splitted[3], ',');
	sphere->material.color.x = ft_atoi(temp_split[0]);
	sphere->material.color.y = ft_atoi(temp_split[1]);
	sphere->material.color.z = ft_atoi(temp_split[2]);
	sphere->material.color = normalize(sphere->material.color);
}

void	sphere_verif(t_sphere *sp, char **map, int i)
{
	char	**splitted;
	splitted = ft_split(map[i], ' ');
	if (count_char(splitted[1], ',') == 2)
		sphere_pos(sp, splitted);
	if (count_char(splitted[2], ',') == 0)
		sp->radius = ft_atof(splitted[2]) / 2;
	if (count_char(splitted[3], ',') == 2 && count_char(splitted[3], '.') == 0 && check_rgb(ft_atoi(splitted[3])))
		sphere_rgb(sp, splitted);
}
