/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dof_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:32:01 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:32:02 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <math.h>
#include <utils.h>

t_rgb	s_dof(t_scene *scene, t_hitrecord *rec)
{
	t_real	t;

	if (scene->camera->dof.enable == false)
		return (s_flat(scene, rec));
	t = vec3_dot(vec3_sub(scene->camera->dof.focal_point, rec->point),
			scene->camera->dof.plane_normal);
	if (t < 0.25 && t > -0.25)
		return ((t_rgb)vec3_id(ID_Y));
	t = fabs(t / scene->camera->dof.focal_dist);
	t = 1 - clamp(t, 0.0, 1.0);
	return ((t_vec3){t, 0.0, 0.0});
}
