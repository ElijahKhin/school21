/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_translate_set_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:17:56 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:17:58 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <events.h>

t_bool	sh_trans_set_rot(t_scene *scene)
{
	if (scene->selected_shape == NULL)
		return (false);
	scene->selection_mode = SELECTION_ROTATE;
	scene->do_update = true;
	console_put(SET_TRANS_MODE_R);
	return (true);
}

t_bool	sh_trans_set_pos(t_scene *scene)
{
	if (scene->selected_shape == NULL)
		return (false);
	scene->selection_mode = SELECTION_TRANSLATE;
	scene->do_update = true;
	console_put(SET_TRANS_MODE_T);
	return (true);
}
