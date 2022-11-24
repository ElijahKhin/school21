/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:31:21 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:31:22 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <minirt.h>
# include <utils.h>

void	construct_cam(t_camera *cam)
{
	t_vec3	origin;
	t_vec3	normal;

	if (cam->dof.enable == false)
		return ;
	origin = mat4_get(cam->world, m_origin);
	normal = mat4_get(cam->world, m_forward);
	cam->dof.focal_point = get_point(origin, normal, cam->dof.focal_dist);
	cam->dof.plane_normal = normal;
}

t_bool	update(t_scene *scene)
{
	construct_cam(scene->camera);
	if (scene->do_update == false)
	{
		scene->do_update = true;
		return (true);
	}
	construct(&scene->shapes);
	if (scene->viewport == brdf && !brdf_render(scene))
		return (false);
	if (scene->viewport != brdf)
		render(scene);
	if (scene->viewport == shaded && scene->aa_enable && !sassaa(scene))
		return (false);
	set_selection(scene);
	mlx_put_image_to_window(scene->mlx.ptr,
		scene->mlx.win, scene->main.image, 0, 0);
	return (true);
}

#endif
