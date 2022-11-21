/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_specularity_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:33:31 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:33:32 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <buffer_bonus.h>
# include <unistd.h>

void	set_specularity(t_hitrecord *rec, t_real u, t_real v)
{
	if (rec->ref->mat.t_specular.map != NULL)
		rec->specular = get_uv_color_at(rec->ref->mat.t_specular.map, u, v);
	else
		rec->specular = rec->ref->mat.specular;
}

#endif
