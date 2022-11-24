/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_intersect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:22:03 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:22:04 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>
# include <utils.h>
# include <math.h>

t_bool	plane_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_plane			*plane;
	t_plane_vars	vars;

	plane = catch->shape;
	vars.pl = vec3_dot(plane->normal, rec->ray.dir);
	if (fabs(vars.pl) < M_EPSILON)
		return (false);
	vars.p = vec3_sub(plane->origin, rec->ray.origin);
	vars.t = vec3_dot(vars.p, plane->normal) / vars.pl;
	if (vars.t <= M_EPSILON || vars.t > rec->distance)
		return (false);
	rec->normal = plane->normal;
	if (vars.pl > 0)
		rec->normal = vec3_mult_s(plane->normal, -1);
	rec->point = get_point(rec->ray.origin, rec->ray.dir, vars.t);
	rec->ref = catch;
	rec->distance = vars.t;
	return (true);
}

#endif
