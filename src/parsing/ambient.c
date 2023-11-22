/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:58:24 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/11/21 19:58:25 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static void	parse_rgb(char **map, t_alight *alight)
{
	char	**splitted;

	splitted = ft_split(map[2], ',');
	if (!splitted)
		map_error("bad split!");
	if (splitted && (!splitted[0] || !splitted[1] || !splitted[2]))
		map_error("Cannot be empty");
	if (ft_strlen(splitted[0]) > 3 || ft_strlen(splitted[1]) > 3
		|| ft_strlen(splitted[2]) > 4)
		map_error("Not rgb value in ambient, must be max 3 digits");
	if (!check_if_all_numbers(splitted[0]) || !check_if_all_numbers(splitted[1])
		|| !check_if_all_numbers(splitted[2]))
		map_error("Only numbers allowed");
	check_rgb(ft_atoi(splitted[0]));
	check_rgb(ft_atoi(splitted[1]));
	check_rgb(ft_atoi(splitted[2]));
	alight->material.color.x = ft_atoi(splitted[0]);
	alight->material.color.y = ft_atoi(splitted[1]);
	alight->material.color.z = ft_atoi(splitted[2]);
	alight->material.color = normalize(alight->material.color);
	ft_x2free((void **)splitted);
}

void	ambient_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (!splitted)
		map_error("bad split!");
	if (!splitted[0] || !splitted[1] || !splitted[2] || splitted[3])
		map_error("Missing arguments need 2 arguments for ambient");
	if (ft_strncmp(splitted[0], "A", 2) == 0)
	{
		if (check_brightness(ft_atof(splitted[1])))
			data->alight.material.bright = ft_atof(splitted[1]);
		else
			map_error("invalid brightness value");
		if (count_char(splitted[2], '.') == 0 && \
			count_char(splitted[2], ',') == 2)
			parse_rgb(splitted, &data->alight);
		else
			map_error("Invalid patern for ambient rgb");
		data->count_alight++;
	}
	ft_x2free((void **)splitted);
}
