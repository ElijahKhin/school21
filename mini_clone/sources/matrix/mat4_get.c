/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:25:40 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:25:41 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

/*
**	Retrieve vectors within matrix
**	mat4_get(matrix, type)
**	type specifiers:
**		m_right, m_up, m_forward, m_origin
*/

t_vec3	mat4_get(t_mat4 m4, t_getmat4elem get)
{
	if (get == m_right)
		return ((t_vec3){m4.data[0][0], m4.data[0][1], m4.data[0][2]});
	if (get == m_up)
		return ((t_vec3){m4.data[1][0], m4.data[1][1], m4.data[1][2]});
	if (get == m_forward)
		return ((t_vec3){m4.data[2][0], m4.data[2][1], m4.data[2][2]});
	if (get == m_origin)
		return ((t_vec3){m4.data[3][0], m4.data[3][1], m4.data[3][2]});
	return (vec3_zero());
}
