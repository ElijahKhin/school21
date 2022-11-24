/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:31:56 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:31:58 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

t_rgb	s_aabb(t_scene *scene, t_hitrecord *rec)
{
	(void)scene;
	if (rec->aabb_hit)
		return ((t_vec3){0.75, 0.0, 0.0});
	return ((t_vec3){0.5, 0.5, 0.5});
}
