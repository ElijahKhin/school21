/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:22:22 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:22:23 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <scene.h>
# include <utils.h>
# include <math.h>

static t_bool	sphere_hit(t_shapes *catch, t_hitrecord *rec, t_real t,
	t_bool inside)
{
	t_sphere	*sphere;

	sphere = catch->shape;
	rec->ref = catch;
	rec->distance = t;
	rec->point = get_point(rec->ray.origin, rec->ray.dir, rec->distance);
	rec->normal = vec3_unit(vec3_sub(rec->point, sphere->origin));
	if (inside)
		rec->normal = vec3_mult_s(rec->normal, -1);
	return (true);
}

t_bool	sphere_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_sphere		*sphere;
	t_sphere_vars	vars;

	sphere = catch->shape;
	vars.t = vec3_dot(vec3_sub(sphere->origin, rec->ray.origin), rec->ray.dir);
	vars.p = get_point(rec->ray.origin, rec->ray.dir, vars.t);
	vars.y = vec3_mag(vec3_sub(sphere->origin, vars.p));
	if (vars.y > sphere->radius)
		return (false);
	vars.x = sqrt(pow_2(sphere->radius) - pow_2(vars.y));
	vars.t1 = vars.t - vars.x;
	if (vars.t1 > M_EPSILON && vars.t1 < rec->distance)
		return (sphere_hit(catch, rec, vars.t1, false));
	vars.t2 = vars.t + vars.x;
	if (vars.t2 > M_EPSILON && vars.t2 < rec->distance)
		return (sphere_hit(catch, rec, vars.t2, true));
	return (false);
}

#endif
