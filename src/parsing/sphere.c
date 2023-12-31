/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:58:51 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/11/21 19:58:52 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

void	check_sphere(t_data *data, char **splitted)
{
	if (count_char(splitted[1], ',') == 2)
		parse_pos(splitted, &data->objs[data->index]);
	else
		map_error("Invalid patern for sphere position");
	if (count_char(splitted[2], ',') == 0)
		data->objs[data->index].radius = ft_atof(splitted[2]) / 2;
	else
		map_error("Invalid patern for sphere radius");
	if (count_char(splitted[3], ',') == 2 && count_char(splitted[3], '.') == 0)
		parse_color(splitted, &data->objs[data->index]);
	else
		map_error("Invalid patern for sphere rgb");
}

void	sphere_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (!splitted)
		map_error("bad split!");
	if (!splitted[0] || !splitted[1] || !splitted[2]
		|| !splitted[3] || splitted[4])
		map_error("Missing arguments need 4 arguments for sphere");
	if (ft_strncmp(splitted[0], "sp", 3) == 0)
	{
		check_sphere(data, splitted);
		data->objs[data->index].intersect_function = &hit_sphere;
		data->index++;
	}
	ft_x2free((void **)splitted);
}
