/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:24:52 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:46:08 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <jump_tables.h>

t_bool	jump_shader(t_scene *scene, t_hitrecord *rec, t_rgb *col)
{
	int						idx;
	static t_jump_shader	js[] = {
	{flat, s_flat},
	{unlit, s_unlit},
	{shaded, s_shaded},
	{aabb, s_aabb},
	{normals, s_normals},
	{units, s_units},
	{uvs, s_uvs},
	{dof, s_dof},
	{none, NULL}
	};

	idx = 0;
	while (js[idx].mode != none && scene->viewport != js[idx].mode)
		idx += 1;
	if (scene->viewport == js[idx].mode)
		*col = js[idx].shader(scene, rec);
	return (true);
}

#endif
