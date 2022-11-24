/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_construct_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:22:00 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:22:01 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <utils.h>

t_bool	plane_construct(t_shapes *catch)
{
	t_plane		*plane;

	plane = catch->shape;
	if (vec3_cmp_s(plane->span_a, 0.0))
		vec3_local_coords(plane->normal, &plane->span_a, &plane->span_b);
	catch->volume.using = false;
	return (true);
}

#endif
