/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersect_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:56:48 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:56:49 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <scene.h>
# include <math.h>
# include <utils.h>

/*
**	Solve quadratics based on ray world coordinates (not axis aligned)
**	Results in infinite cylinder
*/

static void	cylinder_quad(t_cylinder_vars *vars, t_hitrecord *rec,
	t_cylinder *cyl, t_real radius)
{
	t_vec3		dist_to_top;
	t_vec3		dtt_x_diff;
	t_vec3		rd_x_diff;
	t_real		radius_ofs;

	dist_to_top = vec3_sub(rec->ray.origin, cyl->top);
	dtt_x_diff = vec3_cross(dist_to_top, cyl->diff);
	rd_x_diff = vec3_cross(rec->ray.dir, cyl->diff);
	radius_ofs = vec3_dot(cyl->diff, cyl->diff);
	vars->a = vec3_dot(rd_x_diff, rd_x_diff);
	vars->b = 2 * vec3_dot(rd_x_diff, dtt_x_diff);
	vars->c = vec3_dot(dtt_x_diff, dtt_x_diff)
		- (radius * radius * radius_ofs);
	vars->d = vars->b * vars->b - 4 * vars->a * vars->c;
	vars->d_sqr = sqrt(vars->d);
	vars->a_2 = vars->a * 2;
}

/*
**	Check if distance from point centroid is lower than half the height
*/

static t_bool	cylinder_height(t_shapes *catch, t_hitrecord *rec, t_real t,
	t_bool inside)
{
	t_cylinder	*cyl;
	t_vec3		point;
	t_vec3		origin_diff;
	t_real		dist_to_point;
	t_vec3		point_centroid;

	cyl = catch->shape;
	point = get_point(rec->ray.origin, rec->ray.dir, t);
	origin_diff = vec3_sub(cyl->origin, point);
	dist_to_point = vec3_dot(origin_diff, cyl->normal);
	if (fabs(dist_to_point) > cyl->height_d2)
		return (false);
	point_centroid = get_point(cyl->origin, cyl->normal, -dist_to_point);
	rec->distance = t;
	rec->point = point;
	rec->normal = vec3_unit(vec3_sub(point, point_centroid));
	if (inside)
		rec->normal = vec3_negate(rec->normal);
	rec->ref = catch;
	rec->tex.u = (acos(vec3_dot(cyl->span_a, rec->normal)) / M_PI) * 0.5;
	rec->tex.v = vec3_mag(vec3_sub(cyl->top, point_centroid)) / cyl->height;
	if (vec3_dot(cyl->span_b, rec->normal) > 0)
		rec->tex.u = 1 - rec->tex.u;
	return (true);
}

static t_bool	cyl_caps(t_shapes *catch, t_cylinder *cyl, t_hitrecord *rec)
{
	t_shapes	upper;
	t_shapes	lower;
	t_bool		hit;

	upper.shape = (t_disk *)&cyl->upper;
	lower.shape = (t_disk *)&cyl->lower;
	hit = false;
	if (disk_intersect(&upper, rec))
		hit = true;
	if (disk_intersect(&lower, rec))
		hit = true;
	if (hit)
	{
		rec->ref = catch;
		return (true);
	}
	return (false);
}

t_bool	cylinder_intersect(t_shapes *catch, t_hitrecord *rec)
{
	t_cylinder		*cyl;
	t_cylinder_vars	vars;
	t_real			t[2];

	cyl = catch->shape;
	cylinder_quad(&vars, rec, cyl, cyl->radius);
	if (vars.d < 0)
		return (false);
	t[0] = (-vars.b - vars.d_sqr) / vars.a_2;
	if (t[0] >= 0 && t[0] <= rec->distance
		&& cylinder_height(catch, rec, t[0], false))
		return (true);
	if (cyl->capped && cyl_caps(catch, cyl, rec))
		return (true);
	t[1] = (-vars.b + vars.d_sqr) / vars.a_2;
	if (t[1] >= 0 && t[1] <= rec->distance
		&& cylinder_height(catch, rec, t[1], true))
		return (true);
	return (true);
}

#endif
