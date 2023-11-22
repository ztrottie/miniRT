/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_vector_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:59:39 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/11/21 19:59:40 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/maths.h"

t_vec	vec_add(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vec	vec_add_nb(t_vec v1, double add)
{
	t_vec	res;

	res.x = v1.x + add;
	res.y = v1.y + add;
	res.z = v1.z + add;
	return (res);
}

t_vec	vec_sub_nb(t_vec v1, double sub)
{
	t_vec	res;

	res.x = v1.x - sub;
	res.y = v1.y - sub;
	res.z = v1.z - sub;
	return (res);
}

t_vec	vec_mult(double mult, t_vec v1)
{
	t_vec	res;

	res.x = mult * v1.x;
	res.y = mult * v1.y;
	res.z = mult * v1.z;
	return (res);
}

t_vec	vec_div(double div, t_vec v1)
{
	return (vec_mult(1 / div, v1));
}
