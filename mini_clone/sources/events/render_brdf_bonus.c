/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_brdf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:16:50 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:16:52 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <error.h>
# include <minirt.h>

t_bool	render_brdf(t_scene *scene)
{
	if (scene->brdf == false)
	{
		warning_msg(WARN_BRDF_SET);
		scene->brdf_spp = 16;
		scene->brdf_depth = 4;
	}
	console_put(DEBUG_BRDF);
	scene->viewport = brdf;
	return (true);
}

#endif
