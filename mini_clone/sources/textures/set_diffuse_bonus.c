/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_diffuse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:33:11 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:33:13 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <unistd.h>
# include <buffer_bonus.h>

void	set_diffuse(t_hitrecord *rec, t_real u, t_real v)
{
	if (rec->ref->mat.t_diffuse.map == NULL)
		rec->color = rec->ref->mat.diffuse;
	else
		rec->color = get_uv_color_at(rec->ref->mat.t_diffuse.map, u, v);
}

#endif
