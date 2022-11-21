/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:36:00 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:36:02 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <math.h>
#include <unistd.h>

/*
**	Alternative to performing the cross product twice to create a
**	local coordinate system, does not involve as many calculations.
*/

void	vec3_local_coords(const t_vec3 up, t_vec3 *fw, t_vec3 *rt)
{
	if (fabs(up.x) > fabs(up.y))
		*fw = vec3_div_s((t_vec3){up.z, 0, -up.x},
				sqrt(up.x * up.x + up.z * up.z));
	else
		*fw = vec3_div_s((t_vec3){0, -up.z, up.y},
				sqrt(up.y * up.y + up.z * up.z));
	if (rt == NULL)
		return ;
	*rt = vec3_cross(up, *fw);
}
