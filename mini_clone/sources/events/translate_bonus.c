/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:18:23 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:18:24 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>

t_bool	translate(t_scene *scene, t_vec3 *vec)
{
	const t_vec3	identity = (t_vec3){SHAPE_MOVE, SHAPE_MOVE, SHAPE_MOVE};
	t_vec3			fixed_dir;

	fixed_dir = vec3_mult(identity, scene->selection_axis);
	*vec = vec3_add(*vec, fixed_dir);
	return (true);
}
