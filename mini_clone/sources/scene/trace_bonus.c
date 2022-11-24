/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:31:12 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:31:14 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <libft.h>

t_bool	trace(t_scene *scene, t_ray ray, t_rgb *buf_color)
{
	t_hitrecord		record;

	ft_memset(&record, 0, sizeof(t_hitrecord));
	record.ray = ray;
	record.distance = M_INFINITY;
	if (intersect(scene->shapes, &record))
	{
		set_textures(&record, false);
		*buf_color = shade(scene, &record);
		record.ref = NULL;
		return (true);
	}
	else if (scene->viewport == aabb && record.aabb_hit)
		*buf_color = s_aabb(scene, &record);
	else
		*buf_color = set_skybox(scene, record.ray.dir, false);
	record.ref = NULL;
	return (false);
}

#endif
