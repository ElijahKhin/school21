/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_identity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:25:43 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:25:44 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

/*
**	General identity matrix
**	normalized for translation
*/

t_mat4	mat4_identity(void)
{
	t_vec3	right;
	t_vec3	up;
	t_vec3	forward;
	t_vec3	zeroed;

	right = vec3_id(ID_X);
	up = vec3_id(ID_Y);
	forward = vec3_id(ID_Z);
	zeroed = vec3_zero();
	return (mat4(zeroed, forward, right, up));
}
