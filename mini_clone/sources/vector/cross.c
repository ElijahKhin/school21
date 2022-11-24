/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:35:35 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:35:36 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_cross(const t_vec3 right, const t_vec3 forward)
{
	return ((t_vec3){
		right.y * forward.z - right.z * forward.y,
		right.z * forward.x - right.x * forward.z,
		right.x * forward.y - right.y * forward.x});
}
