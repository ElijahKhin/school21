/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:55:57 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:55:58 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <minirt.h>
# include <parse.h>
# include <utils.h>
# include <init.h>

t_bool	scene_init(t_scene *scene, char *rt_file)
{
	console_put(SCENE_INIT);
	rand_init();
	scene->mlx.ptr = mlx_init();
	scene->viewport = flat;
	scene->viewport_scale = 2;
	scene->ambience = -1;
	scene->cam_idx = 1;
	scene->do_update = true;
	if (!parse_to_scene(scene, rt_file))
		return (false);
	return (scene_verify(scene));
}

#endif
