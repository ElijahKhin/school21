/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_construct_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:22:43 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:22:44 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <init.h>

t_bool	triangle_construct(t_shapes *catch)
{
	t_triangle	*tri;

	tri = catch->shape;
	tri->edge[0] = vec3_sub(tri->vert[1], tri->vert[0]);
	tri->edge[1] = vec3_sub(tri->vert[2], tri->vert[1]);
	tri->edge[2] = vec3_sub(tri->vert[0], tri->vert[2]);
	tri->normal = vec3_cross(tri->edge[2], tri->edge[0]);
	tri->denom = 1 / vec3_dot(tri->normal, tri->normal);
	tri->traverse = -vec3_dot(tri->normal, tri->vert[0]);
	tri->dot_aa = vec3_dot(tri->edge[0], tri->edge[0]);
	tri->dot_ab = vec3_dot(tri->edge[0], tri->edge[1]);
	tri->dot_bb = vec3_dot(tri->edge[1], tri->edge[1]);
	volume_init(&catch->volume);
	volume_add_vec(&catch->volume, tri->vert[0]);
	volume_add_vec(&catch->volume, tri->vert[1]);
	volume_add_vec(&catch->volume, tri->vert[2]);
	return (true);
}

#endif
