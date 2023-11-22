/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbeaumon <zbeaumon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:59:43 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/11/21 19:59:44 by zbeaumon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/maths.h"

t_vec	cross_product(t_vec v1, t_vec v2)
{
	t_vec	res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}
