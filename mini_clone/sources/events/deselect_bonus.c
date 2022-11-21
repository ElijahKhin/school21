/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deselect_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:54:02 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:54:03 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <events.h>

t_bool	sh_deselect(t_scene *scene)
{
	if (scene->selected_shape || scene->selection_mode)
	{
		console_put(SH_DESELECT);
		scene->selected_shape = NULL;
		scene->selection_mode = SELECTION_UNDEFINED;
		scene->selection_axis = vec3_zero();
		scene->do_update = true;
	}
	return (true);
}
