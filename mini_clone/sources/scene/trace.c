/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:31:09 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:31:10 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>
# include <libft.h>

t_bool	trace(t_scene *scene, t_ray ray, t_rgb *buf_color)
{
	t_hitrecord		record;

	ft_memset(&record, 0, sizeof(t_hitrecord));
	record.ray = ray;
	record.distance = M_INFINITY;
	record.ray.max = M_INFINITY;
	*buf_color = vec3_zero();
	if (intersect(scene->shapes, &record))
	{
		record.color = record.ref->mat.diffuse;
		*buf_color = shade(scene, &record);
		record.ref = NULL;
		return (true);
	}
	else if (scene->viewport == aabb && record.aabb_hit)
		*buf_color = s_aabb(scene, &record);
	record.ref = NULL;
	return (false);
}

#endif
