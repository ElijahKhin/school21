/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_translate_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:16:32 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:16:34 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	plane_translate(t_scene *scene)
{
	t_plane	*plane;
	t_mat4	orient;

	plane = (t_plane *)scene->selected_shape->shape;
	orient = mat4(plane->origin, plane->span_b, plane->span_a, plane->normal);
	if (scene->selection_mode == SELECTION_TRANSLATE)
		return (translate(scene, &plane->origin));
	if (scene->selection_mode == SELECTION_ROTATE)
	{
		rotate(scene, &orient);
		plane->normal = vec3_unit(mat4_get(orient, m_up));
		plane->span_a = vec3_unit(mat4_get(orient, m_right));
		plane->span_b = vec3_unit(mat4_get(orient, m_forward));
	}
	return (true);
}
