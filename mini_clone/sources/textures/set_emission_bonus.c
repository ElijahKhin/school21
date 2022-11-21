/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_emission_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:33:16 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:33:17 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <buffer_bonus.h>
# include <unistd.h>

void	set_emission(t_hitrecord *rec, t_real u, t_real v)
{
	if (rec->ref->mat.t_emission.map == NULL)
		rec->emission = rec->ref->mat.emission;
	else
		rec->emission = vec3_mult_s(get_uv_color_at(
					rec->ref->mat.t_emission.map, u, v), 10);
}

#endif
