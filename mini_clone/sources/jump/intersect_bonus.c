/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:24:27 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:43:35 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <jump_tables.h>

t_bool	jump_intersect(t_shapes *shape, t_hitrecord *rec)
{
	int						idx;
	static t_jump_intersect	is[] = {
	{sh_sphere, sphere_intersect},
	{sh_plane, plane_intersect},
	{sh_square, square_intersect},
	{sh_cylinder, cylinder_intersect},
	{sh_triangle, triangle_intersect},
	{sh_disk, disk_intersect},
	{sh_cube, cube_intersect},
	{sh_pyramid, pyramid_intersect},
	{sh_trimesh, trimesh_intersect},
	{sh_noshape, NULL}	
	};

	idx = 0;
	while (is[idx].type != sh_noshape && shape->type != is[idx].type)
		idx += 1;
	if (shape->type == is[idx].type)
		return (is[idx].intersect(shape, rec));
	return (false);
}

#endif
