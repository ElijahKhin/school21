/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:36:12 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:36:13 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_reflect(const t_vec3 vec, const t_vec3 normal)
{
	t_vec3	rfl;

	rfl = vec3_mult_s(vec3_mult_s(normal, 2), vec3_dot(vec, normal));
	return (vec3_unit(vec3_sub(vec, rfl)));
}

t_vec3	vec3_bounce(const t_vec3 vec, const t_vec3 normal)
{
	return (vec3_negate(vec3_reflect(vec, normal)));
}
