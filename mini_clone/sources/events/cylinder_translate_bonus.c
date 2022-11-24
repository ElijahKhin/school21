/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_translate_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:53:59 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:54:00 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	cylinder_translate(t_scene *scene)
{
	t_cylinder	*cyl;
	t_mat4		orient;

	cyl = (t_cylinder *)scene->selected_shape->shape;
	orient = mat4(cyl->origin, cyl->span_b, cyl->span_a, cyl->normal);
	if (scene->selection_mode == SELECTION_TRANSLATE)
		return (translate(scene, &cyl->origin));
	if (scene->selection_mode == SELECTION_ROTATE)
	{
		rotate(scene, &orient);
		cyl->normal = vec3_unit(mat4_get(orient, m_up));
		cyl->span_a = vec3_unit(mat4_get(orient, m_right));
		cyl->span_b = vec3_unit(mat4_get(orient, m_forward));
	}
	return (true);
}
