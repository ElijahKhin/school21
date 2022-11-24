/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_axis_set_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:17:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:17:50 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <events.h>

t_bool	sh_set_axis_x(t_scene *scene)
{
	if (scene->selection_mode == SELECTION_UNDEFINED)
		return (false);
	scene->selection_axis = vec3_id(ID_X);
	scene->do_update = false;
	console_put(SET_AXIS_X);
	return (true);
}

t_bool	sh_set_axis_y(t_scene *scene)
{
	if (scene->selection_mode == SELECTION_UNDEFINED)
		return (false);
	scene->selection_axis = vec3_id(ID_Y);
	scene->do_update = false;
	console_put(SET_AXIS_Y);
	return (true);
}

t_bool	sh_set_axis_z(t_scene *scene)
{
	if (scene->selection_mode == SELECTION_UNDEFINED)
		return (false);
	scene->selection_axis = vec3_id(ID_Z);
	scene->do_update = false;
	console_put(SET_AXIS_Z);
	return (true);
}
