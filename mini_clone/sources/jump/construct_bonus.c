/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:24:20 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:41:42 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <jump_tables.h>

t_bool	jump_construct(t_shapes *shape)
{
	int						idx;
	static t_jump_construct	cs[] = {
	{sh_sphere, sphere_construct}, {sh_plane, plane_construct},
	{sh_square, square_construct}, {sh_cylinder, cylinder_construct},
	{sh_triangle, triangle_construct}, {sh_disk, disk_construct},
	{sh_cube, cube_construct}, {sh_pyramid, pyramid_construct},
	{sh_trimesh, trimesh_construct}, {sh_noshape, NULL}	
	};

	idx = 0;
	if (shape->construct == false)
		return (true);
	while (cs[idx].type != sh_noshape && shape->type != cs[idx].type)
		idx += 1;
	if (shape->type == cs[idx].type)
	{
		cs[idx].construct(shape);
		shape->construct = false;
		return (true);
	}
	return (false);
}

#endif
