/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rot_around.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:26:01 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:26:02 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_mat4	mat4_rota(t_mat4 src, t_vec3 point, t_vec3 angle)
{
	src = mat4_sub_vec(src, point);
	src = mat4_mult(src, mat4_rotate(angle));
	src = mat4_add_vec(src, point);
	return (src);
}
