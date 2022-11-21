/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_x_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:18:11 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:18:14 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	move_right(t_scene *scene)
{
	t_vec3		right;

	right = mat4_get(scene->camera->world, m_right);
	right = vec3_mult_s(right, CAM_MOVE);
	scene->camera->world = mat4_add_vec(scene->camera->world, right);
	return (true);
}

t_bool	move_left(t_scene *scene)
{
	t_vec3		left;

	left = mat4_get(scene->camera->world, m_right);
	left = vec3_mult_s(left, -CAM_MOVE);
	scene->camera->world = mat4_add_vec(scene->camera->world, left);
	return (true);
}

t_bool	pitch_up(t_scene *scene)
{
	scene->camera->world = mat4_mult(mat4_rotx(CAM_LOOK),
			scene->camera->world);
	return (true);
}

t_bool	pitch_down(t_scene *scene)
{
	scene->camera->world = mat4_mult(mat4_rotx(-CAM_LOOK),
			scene->camera->world);
	return (true);
}
