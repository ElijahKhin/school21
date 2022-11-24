/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_construct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:56:38 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:56:39 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <shapes.h>
# include <math.h>
# include <init.h>

t_bool	cylinder_construct(t_shapes *catch)
{
	t_cylinder	*cyl;
	t_vec3		nml_inv;
	t_vec3		center_rad;

	cyl = catch->shape;
	cyl->height_d2 = cyl->height / 2;
	cyl->half_height = vec3_mult_s(cyl->normal, cyl->height / 2);
	cyl->top = vec3_add(cyl->origin, cyl->half_height);
	cyl->bottom = vec3_sub(cyl->origin, cyl->half_height);
	cyl->diff = vec3_sub(cyl->bottom, cyl->top);
	nml_inv = vec3_sub((t_vec3){1.0, 1.0, 1.0}, vec3_div_s(
				vec3_mult(cyl->diff, cyl->diff),
				vec3_dot(cyl->diff, cyl->diff)));
	center_rad = (t_vec3){
		cyl->radius * sqrt(nml_inv.x),
		cyl->radius * sqrt(nml_inv.y),
		cyl->radius * sqrt(nml_inv.z)};
	volume_init(&catch->volume);
	volume_add_vec(&catch->volume, vec3_sub(cyl->top, center_rad));
	volume_add_vec(&catch->volume, vec3_add(cyl->top, center_rad));
	volume_add_vec(&catch->volume, vec3_sub(cyl->bottom, center_rad));
	volume_add_vec(&catch->volume, vec3_add(cyl->bottom, center_rad));
	return (true);
}

#endif
