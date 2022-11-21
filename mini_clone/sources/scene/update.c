/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:31:17 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:31:18 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>

t_bool	update(t_scene *scene)
{
	construct(&scene->shapes);
	render(scene);
	mlx_put_image_to_window(scene->mlx.ptr,
		scene->mlx.win, scene->main.image, 0, 0);
	return (true);
}

#endif
