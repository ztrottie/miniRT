/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_viewport.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:59:59 by zbeaumon          #+#    #+#             */
/*   Updated: 2023/12/21 14:33:26 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/run.h"

static t_vec	vp_upper_left(t_viewport *vp)
{
	t_vec	v1;
	t_vec	v2;

	v1 = vec_sub_vec(init_vec(0, 0, 0), init_vec(0, 0, vp->focal_len));
	v2 = vec_sub_vec(v1, vec_div(2, vp->vp_u));
	return (vec_sub_vec(v2, vec_div(2, vp->vp_v)));
}

static t_vec	vp_p00_loc(t_viewport *vp)
{
	t_vec	v1;

	v1 = vec_add(vp->delta_u, vp->delta_v);
	return (vec_add(vp->upper_left, vec_mult(0.5, v1)));
}

void	init_viewport(t_data *data)
{
	t_viewport	*vp;

	vp = &data->base_vp;
	vp->vp_height = 2.0;
	vp->vp_width = vp->vp_height * (((double)WIDTH / data->img_height));
	printf("%f\n", vp->vp_width);
	vp->focal_len = (vp->vp_width / 2) / tan((data->fov * M_PI / 180)/ 2);
	printf("%f\n", vp->focal_len);
	vp->vp_center = vec_sub_vec(init_vec(0, 0, 0), \
	init_vec(0, 0, -vp->focal_len));
	vp->vp_v = init_vec(vp->vp_width, 0, 0);
	vp->vp_u = init_vec(0, -vp->vp_height, 0);
	vp->delta_v = vec_div(WIDTH, vp->vp_v);
	vp->delta_u = vec_div(data->img_height, vp->vp_u);
	vp->upper_left = vp_upper_left(vp);
	vp->p00_loc = vp_p00_loc(vp);
}
