/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:55:38 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:55:39 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>

t_bool	camera_ray_init(t_scene *scene, t_ray *ray, t_real u, t_real v)
{
	t_vec3		worldspace;

	worldspace.x = (2 * ((u + 0.5) / scene->mlx.width) - 1)
		* scene->camera->view_range * scene->ratio;
	worldspace.y = (1 - 2 * ((v + 0.5) / scene->mlx.height))
		* scene->camera->view_range;
	worldspace.z = 1;
	ray->origin = mat4_get(scene->camera->world, m_origin);
	ray->dir = vec3_unit(mat4_mult_dir(scene->camera->world,
				worldspace));
	ray->max = M_INFINITY;
	return (true);
}

#endif