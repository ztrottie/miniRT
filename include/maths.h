/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:01:28 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/11/21 20:01:29 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

# include "minirt.h"

double		sqr(double a);
double		dot_product(t_vec v1, t_vec v2);
t_vec		cross_product(t_vec v1, t_vec v2);
t_vec		vec_div(double div, t_vec v1);
t_vec		vec_mult(double mult, t_vec v1);
t_vec		vec_add(t_vec v1, t_vec v2);
t_vec		vec_sub_vec(t_vec v1, t_vec v2);
t_vec		vec_sub_nb(t_vec v1, double sub);
t_vec		vec_add_nb(t_vec v1, double add);
double		vec_dist(t_vec v1, t_vec v2);;
t_vec		normalize(t_vec vec);
double		vector_length(t_vec vec);
t_point		ray_at(t_ray ray, double t);
t_vec		rotation_y(t_vec vec, double deg);
t_vec		rotation_x(t_vec vec, double deg);
t_vec		rotation_z(t_vec vec, double deg);
t_vec		vec_mult_vec(t_vec v1, t_vec v2);

#endif