/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:36:06 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:36:07 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_mult(const t_vec3 one, const t_vec3 two)
{
	return ((t_vec3){one.x * two.x, one.y * two.y, one.z * two.z});
}

t_vec3	vec3_mult_s(const t_vec3 one, const t_real two)
{
	return ((t_vec3){one.x * two, one.y * two, one.z * two});
}
