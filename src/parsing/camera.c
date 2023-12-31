/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:58:27 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/11/21 19:58:28 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"

static void	parse_cam_pos(char **map, t_data *data)
{
	char	**splitted;

	splitted = ft_split(map[1], ',');
	if (!splitted)
		map_error("bad split!");
	if (splitted && (!splitted[0] || !splitted[1] || !splitted[2]))
		map_error("Cannot be emty in cam pos");
	if (!check_if_all_numbers(splitted[0]) || !check_if_all_numbers(splitted[1])
		|| !check_if_all_numbers(splitted[2]))
		map_error("Only numbers allowed");
	data->cam.x = ft_atof(splitted[0]);
	data->cam.y = ft_atof(splitted[1]);
	data->cam.z = ft_atof(splitted[2]);
	ft_x2free((void **)splitted);
}

static void	parse_cam_vec(char **map, t_data *data)
{
	char	**splitted;

	splitted = ft_split(map[2], ',');
	if (!splitted)
		map_error("bad split!");
	if (splitted && (!splitted[0] || !splitted[1] || !splitted[2]))
		map_error("Must be at least 0 in cam vec");
	if (!check_if_all_numbers(splitted[0]) || !check_if_all_numbers(splitted[1])
		|| !check_if_all_numbers(splitted[2]))
		map_error("Only numbers allowed");
	data->cam_dir.x = ft_atof(splitted[0]);
	data->cam_dir.y = ft_atof(splitted[1]);
	data->cam_dir.z = ft_atof(splitted[2]);
	ft_x2free((void **)splitted);
}

void	check_cam(t_data *data, char **splitted)
{
	if (count_char(splitted[1], ',') == 2)
		parse_cam_pos(splitted, data);
	else
		map_error("Invalid patern for camera position");
	if (count_char(splitted[2], ',') == 2)
		parse_cam_vec(splitted, data);
	else
		map_error("Invalid patern for camera vector");
	if (ft_atoi(splitted[3]) >= 0 && ft_atoi(splitted[3]) <= 180
		&& count_char(splitted[3], ',') == 0)
		data->fov = ft_atoi(splitted[3]);
	else
		map_error("Fov must be between 0-180");
	data->count_cam++;
}

void	camera_verif(t_data *data, char **map, int i)
{
	char	**splitted;

	splitted = ft_split(map[i], ' ');
	if (!splitted)
		map_error("bad split!");
	if (!splitted[0] || !splitted[1] || !splitted[2]
		|| !splitted[3] || splitted[4])
		map_error("Missing arguments need 3 arguments for camera");
	if (ft_strncmp(splitted[0], "C", 2) == 0)
	{
		check_cam(data, splitted);
	}
	ft_x2free((void **)splitted);
}
