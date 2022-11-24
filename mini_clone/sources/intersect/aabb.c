/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:56:15 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:56:17 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shapes.h>
#include <math.h>

static t_real	max(t_real one, t_real two)
{
	if (one < two)
		return (two);
	return (one);
}

static t_real	min(t_real one, t_real two)
{
	if (one > two)
		return (two);
	return (one);
}

t_bool	volume_centroid(t_aabb *volume)
{
	volume->centroid = vec3_add(vec3_mult_s(vec3_sub(
					volume->max, volume->min), 0.5), volume->min);
	return (true);
}

t_bool	volume_add_vec(t_aabb *volume, t_vec3 vec)
{
	volume->min = (t_vec3){
		min(volume->min.x, vec.x),
		min(volume->min.y, vec.y),
		min(volume->min.z, vec.z)};
	volume->max = (t_vec3){
		max(volume->max.x, vec.x),
		max(volume->max.y, vec.y),
		max(volume->max.z, vec.z)};
	return (true);
}
