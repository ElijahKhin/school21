/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uvs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:32:29 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:32:30 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <utils.h>

t_rgb	s_uvs(t_scene *scene, t_hitrecord *rec)
{
	t_rgb	col;
	t_real	u;
	t_real	v;

	(void)scene;
	u = set_tiling(rec->tex.u, rec->ref->mat.tex_size_x);
	v = set_tiling(rec->tex.v, rec->ref->mat.tex_size_y);
	col.x = u;
	col.y = v;
	col.z = 1 - col.x - col.y;
	return (vec3_clamp(col, 0, 1));
}

#endif
