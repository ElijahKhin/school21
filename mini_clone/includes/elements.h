/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:50:52 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:50:53 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENTS_H
# define ELEMENTS_H
# include <alias.h>
# include <vector.h>
# include <matrix.h>
# include <color.h>
# if IS_BONUS == 1
#  include <elements_bonus.h>
# else

typedef struct s_lights
{
	t_vec3		origin;
	t_real		intensity;
	t_rgb		color;
	t_vec3		dir;
	t_real		dist;
	t_real		angle;
	void		*next;
}	t_lights;

typedef struct s_camera
{
	t_vec3		origin;
	t_vec3		normal;
	t_real		fov;
	t_real		view_range;
	t_mat4		world;
}	t_camera;

# endif

typedef struct s_camlist
{
	int			id;
	t_camera	*cam;
	void		*next;
}	t_camlist;

#endif
