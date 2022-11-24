/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dof_adjust_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:54:09 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:54:12 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <events.h>

t_bool	dof_adjust_dn(t_scene *scene)
{
	scene->do_update = false;
	if (scene->viewport != dof)
		return (false);
	scene->do_update = true;
	scene->camera->dof.focal_dist -= DOF_DIST_SCALE;
	return (true);
}

t_bool	dof_adjust_up(t_scene *scene)
{
	scene->do_update = false;
	if (scene->viewport != dof)
		return (false);
	scene->do_update = true;
	scene->camera->dof.focal_dist += DOF_DIST_SCALE;
	return (true);
}
