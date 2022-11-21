/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reflection_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:33:24 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:33:26 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <buffer_bonus.h>
# include <unistd.h>

void	set_reflection(t_hitrecord *rec, t_real u, t_real v)
{
	if (rec->ref->mat.t_reflection.map != NULL)
		rec->reflection = get_uv_color_at(rec->ref->mat.t_reflection.map, u, v);
	else
		rec->reflection = rec->ref->mat.reflection;
}

#endif
