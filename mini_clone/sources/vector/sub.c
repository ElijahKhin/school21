/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:36:15 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:36:16 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_vec3	vec3_sub(const t_vec3 one, const t_vec3 two)
{
	return ((t_vec3){one.x - two.x, one.y - two.y, one.z - two.z});
}

t_vec3	vec3_sub_s(const t_vec3 one, const t_real two)
{
	return ((t_vec3){one.x - two, one.y - two, one.z - two});
}
