/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:35:26 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:35:27 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <shapes.h>

t_bool	vec3_is_bounds(const t_vec3 in, const t_aabb volume)
{
	if (in.x >= volume.min.x
		&& in.y >= volume.min.y
		&& in.z >= volume.min.z
		&& in.x <= volume.max.x
		&& in.y <= volume.max.y
		&& in.z <= volume.max.z)
		return (true);
	return (false);
}
