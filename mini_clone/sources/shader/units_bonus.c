/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   units_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:32:21 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:32:22 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <math.h>

t_rgb	s_units(t_scene *scene, t_hitrecord *rec)
{
	int		add;

	(void)scene;
	add = floor(rec->point.x + M_EPSILON)
		+ floor(rec->point.y + M_EPSILON)
		+ floor(rec->point.z + M_EPSILON);
	if (add % 2)
		return ((t_vec3){1.0, 1.0, 1.0});
	return (vec3_zero());
}
