/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:54:24 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:54:25 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <minirt.h>
# include <stdlib.h>

t_bool	free_and_exit(t_scene *scene)
{
	destroy_mlx(scene);
	free_cameras(&scene->cameras);
	free_shapes(&scene->shapes);
	free_lights(&scene->lights);
	free_scene(scene);
	console_put(RT_EXIT);
	exit (1);
	return (true);
}

#endif
