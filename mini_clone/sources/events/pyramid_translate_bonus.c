/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_translate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:16:38 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:16:39 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	pyramid_translate(t_scene *scene)
{
	t_pyramid	*pyr;
	t_mat4		orient;

	pyr = (t_pyramid *)scene->selected_shape->shape;
	if (scene->selection_mode == SELECTION_TRANSLATE)
		return (translate(scene, &pyr->origin));
	if (scene->selection_mode == SELECTION_ROTATE)
	{
		orient = mat4(pyr->origin, pyr->span_b, pyr->span_a, pyr->normal);
		rotate(scene, &orient);
		pyr->normal = vec3_unit(mat4_get(orient, m_up));
		pyr->span_a = vec3_unit(mat4_get(orient, m_right));
		pyr->span_b = vec3_unit(mat4_get(orient, m_forward));
	}
	return (true);
}
