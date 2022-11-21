/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_construct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:59:25 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:59:26 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shapes.h>
#include <init.h>

t_bool	sphere_construct(t_shapes *catch)
{
	t_sphere	*sphere;

	sphere = catch->shape;
	volume_init(&catch->volume);
	catch->volume.min = vec3_sub_s(sphere->origin, sphere->radius);
	catch->volume.max = vec3_add_s(sphere->origin, sphere->radius);
	return (true);
}
