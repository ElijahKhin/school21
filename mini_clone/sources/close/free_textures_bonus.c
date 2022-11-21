/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:52:00 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:52:01 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <stdlib.h>

void	free_textures(t_scene *scene, t_texture **list)
{
	t_texture	*start;
	t_texture	*next;

	console_put(RT_FREE_TEXTURES);
	start = *list;
	while (start)
	{
		next = start->next;
		free(start->file);
		mlx_destroy_image(scene->mlx.ptr, start->map->image);
		free(start->map);
		free(start);
		start = next;
	}
	*list = NULL;
}
