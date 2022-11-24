/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:51:38 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:51:39 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <minirt.h>

void	destroy_mlx(t_scene *scene)
{
	console_put(RT_DESTROY);
	if (scene->main.image)
		mlx_destroy_image(scene->mlx.ptr, scene->main.image);
	if (scene->selection.image)
		mlx_destroy_image(scene->mlx.ptr, scene->selection.image);
	if (scene->mlx.win)
		mlx_destroy_window(scene->mlx.ptr, scene->mlx.win);
}

#endif
