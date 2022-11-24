/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:25:58 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:25:59 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>
#include <math.h>

t_mat4	mat4_rotz(t_real degrees)
{
	t_mat4		rotate;
	t_real		radians;

	radians = degrees * M_PI / 180;
	rotate = mat4_identity();
	rotate.data[0][0] = cos(radians);
	rotate.data[0][1] = -sin(radians);
	rotate.data[1][0] = sin(radians);
	rotate.data[1][1] = cos(radians);
	return (rotate);
}

t_mat4	mat4_roty(t_real degrees)
{
	t_mat4		rotate;
	t_real		radians;

	radians = degrees * M_PI / 180;
	rotate = mat4_identity();
	rotate.data[0][0] = cos(radians);
	rotate.data[0][2] = sin(radians);
	rotate.data[2][0] = -sin(radians);
	rotate.data[2][2] = cos(radians);
	return (rotate);
}

t_mat4	mat4_rotx(t_real degrees)
{
	t_mat4		rotate;
	t_real		radians;

	radians = degrees * M_PI / 180;
	rotate = mat4_identity();
	rotate.data[1][1] = cos(radians);
	rotate.data[1][2] = -sin(radians);
	rotate.data[2][1] = sin(radians);
	rotate.data[2][2] = cos(radians);
	return (rotate);
}

t_mat4	mat4_rotate(const t_vec3 rotate)
{
	return (mat4_mult(mat4_mult(
				mat4_rotz(rotate.z)
				, mat4_roty(rotate.y)), mat4_rotx(rotate.x)));
}
