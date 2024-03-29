/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:30:46 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:30:47 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <init.h>
# include <minirt.h>
# include <utils.h>

t_bool	render(t_scene *scene)
{
	t_rgb	color;
	t_ray	ray;

	scene->u = 0;
	scene->v = 0;
	scene->completion = 0;
	while (scene->u < scene->main.width)
	{
		while (scene->v < scene->main.height)
		{
			camera_ray_init(scene, &ray, scene->u, scene->v);
			trace(scene, ray, &color);
			write_color_at(&scene->main, scene->u, scene->v, color);
			scene->v += 1;
		}
		if (scene->viewport == shaded)
			scene_completion(&scene->completion, scene->prog_add);
		scene->v = 0;
		scene->u += 1;
	}
	return (true);
}

#endif
