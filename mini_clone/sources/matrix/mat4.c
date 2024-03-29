/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:25:30 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:25:31 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

/*
**	Initializing a new four by four matrix using the cartesian coordinates
**	As well as the origin of the cartesian system in world space
*/

t_mat4	mat4(t_vec3 origin, t_vec3 forward, t_vec3 right, t_vec3 up)
{
	t_mat4		coords;

	coords.data[0][0] = right.x;
	coords.data[0][1] = right.y;
	coords.data[0][2] = right.z;
	coords.data[0][3] = 0;
	coords.data[1][0] = up.x;
	coords.data[1][1] = up.y;
	coords.data[1][2] = up.z;
	coords.data[1][3] = 0;
	coords.data[2][0] = forward.x;
	coords.data[2][1] = forward.y;
	coords.data[2][2] = forward.z;
	coords.data[2][3] = 0;
	coords.data[3][0] = origin.x;
	coords.data[3][1] = origin.y;
	coords.data[3][2] = origin.z;
	coords.data[3][3] = 1;
	return (coords);
}
