/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_y_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:18:16 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:18:17 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	move_down(t_scene *scene)
{
	t_vec3		down;

	down = mat4_get(scene->camera->world, m_up);
	down = vec3_mult_s(down, -CAM_MOVE);
	scene->camera->world = mat4_add_vec(scene->camera->world, down);
	return (true);
}

t_bool	move_up(t_scene *scene)
{
	t_vec3		down;

	down = mat4_get(scene->camera->world, m_up);
	down = vec3_mult_s(down, CAM_MOVE);
	scene->camera->world = mat4_add_vec(scene->camera->world, down);
	return (true);
}

t_bool	yaw_right(t_scene *scene)
{
	scene->camera->world = mat4_mult(mat4_roty(-CAM_LOOK),
			scene->camera->world);
	return (true);
}

t_bool	yaw_left(t_scene *scene)
{
	scene->camera->world = mat4_mult(mat4_roty(CAM_LOOK),
			scene->camera->world);
	return (true);
}
