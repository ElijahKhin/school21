/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:55:35 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:55:36 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <minirt.h>

t_bool	buffer_init(t_scene *scene)
{
	console_put(WIN_INIT);
	scene->mlx.win = mlx_new_window(scene->mlx.ptr, scene->mlx.width,
			scene->mlx.height, RT_TITLE);
	console_put(BUF_INIT);
	if (!new_buffer(&scene->main, scene->mlx.ptr,
			scene->mlx.width, scene->mlx.height))
		return (false);
	if (!new_buffer(&scene->selection, scene->mlx.ptr,
			scene->mlx.width, scene->mlx.height))
		return (false);
	if (scene->mlx.win == NULL)
		return (false);
	return (true);
}

#endif
