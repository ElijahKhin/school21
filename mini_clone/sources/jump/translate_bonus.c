/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:24:58 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 19:12:41 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <jump_tables.h>
#include <events.h>

t_bool	jump_translate(t_scene *scene)
{
	int						idx;
	static t_jump_translate	jt[] = {
	{sh_sphere, sphere_translate},
	{sh_plane, plane_translate},
	{sh_square, square_translate},
	{sh_cylinder, cylinder_translate},
	{sh_triangle, triangle_translate},
	{sh_disk, disk_translate},
	{sh_cube, cube_translate},
	{sh_pyramid, pyramid_translate},
	{sh_trimesh, trimesh_translate},
	{sh_noshape, NULL}	
	};

	idx = 0;
	while (jt[idx].type != sh_noshape
		&& scene->selected_shape->type != jt[idx].type)
		idx += 1;
	if (scene->selected_shape->type == jt[idx].type)
		return (jt[idx].translate(scene));
	scene->do_update = false;
	return (false);
}
