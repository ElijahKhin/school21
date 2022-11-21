/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:51:34 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:51:35 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include "minirt.h"

void	destroy_mlx(t_scene *scene)
{
	console_put(RT_DESTROY);
	if (scene->main.image)
		mlx_destroy_image(scene->mlx.ptr, scene->main.image);
	if (scene->mlx.win)
		mlx_destroy_window(scene->mlx.ptr, scene->mlx.win);
}

#endif
