/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_dof_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:16:55 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:16:59 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_dof(t_scene *scene)
{
	if (scene->camera->dof.enable == false)
		return (false);
	scene->viewport = dof;
	console_put(DEBUG_DOF);
	return (true);
}
