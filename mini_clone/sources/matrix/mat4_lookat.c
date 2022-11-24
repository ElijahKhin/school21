/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_lookat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:25:47 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:25:48 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>
#include <math.h>

t_mat4	lookat_edge(t_vec3 origin, t_vec3 look_at)
{
	t_vec3		forward;
	t_vec3		right;
	t_vec3		up;

	forward = vec3_unit(vec3_mult_s(vec3_sub(origin, look_at), -1));
	right = vec3_id(ID_X);
	up = vec3_cross(forward, right);
	return (mat4(origin, forward, right, up));
}

t_mat4	mat4_lookat(t_vec3 origin, t_vec3 look_at)
{
	t_vec3		check;
	t_vec3		up_tmp;
	t_vec3		forward;
	t_vec3		right;
	t_vec3		up;

	check = vec3_unit(look_at);
	if (check.x == 0.0 && fabs(check.y) == 1.0 && check.z == 0.0)
	{
		forward = vec3_unit(vec3_mult_s(vec3_sub(origin, look_at), -1));
		right = vec3_id(ID_X);
	}
	else
	{
		up_tmp = vec3_id(ID_Y);
		forward = vec3_unit(vec3_mult_s(vec3_sub(origin, look_at), -1));
		right = vec3_cross(up_tmp, forward);
	}
	up = vec3_cross(forward, right);
	return (mat4(origin, forward, right, up));
}
