/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_roughness_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:33:29 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:33:30 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <buffer_bonus.h>
# include <unistd.h>
# include <utils.h>

/*
**	Side note, gloss is the same as roughness, just inverted
*/

void	set_roughness(t_hitrecord *rec, t_real u, t_real v)
{
	if (rec->ref->mat.t_roughness.map != NULL)
		rec->roughness = greyscale(
				get_uv_color_at(rec->ref->mat.t_roughness.map, u, v));
	else
		rec->roughness = rec->ref->mat.roughness;
}

#endif
