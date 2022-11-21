/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fov_adjust_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:54:15 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:54:16 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <events.h>

t_bool	fov_increase(t_scene *scene)
{
	scene->camera->fov += FOV_SCALAR;
	scene->do_update = true;
	scene->camera->view_range = tan((scene->camera->fov * 0.5) * (M_PI / 180));
	return (true);
}

t_bool	fov_decrease(t_scene *scene)
{
	scene->camera->fov -= FOV_SCALAR;
	scene->do_update = true;
	scene->camera->view_range = tan((scene->camera->fov * 0.5) * (M_PI / 180));
	return (true);
}
