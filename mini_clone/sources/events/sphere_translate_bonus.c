/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_translate_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:18:00 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:18:01 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	sphere_translate(t_scene *scene)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)scene->selected_shape->shape;
	if (scene->selection_mode == SELECTION_TRANSLATE)
		return (translate(scene, &sphere->origin));
	return (true);
}
