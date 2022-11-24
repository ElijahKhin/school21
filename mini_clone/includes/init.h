/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:51:09 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:51:09 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H
# include <scene.h>
# include <shapes.h>
# if IS_BONUS == 1
#  include <init_bonus.h>
# endif

t_bool		scene_init(t_scene *scene, char *rt_file);
t_scene		*scene_allocate(void);
t_bool		scene_verify(t_scene *scene);
t_bool		buffer_init(t_scene *scene);
t_bool		hook_init(t_scene *scene);
t_bool		camera_ray_init(t_scene *scene, t_ray *ray, t_real u, t_real v);
t_bool		volume_init(t_aabb *volume);

#endif
