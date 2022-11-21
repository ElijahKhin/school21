/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:35:32 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:35:33 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <alias.h>
#include <math.h>

t_bool	vec3_cmp(const t_vec3 one, const t_vec3 two)
{
	if (fabs(one.x - two.x) < M_EPSILON
		&& fabs(one.y - two.y) < M_EPSILON
		&& fabs(one.z - two.z) < M_EPSILON)
		return (true);
	return (false);
}

t_bool	vec3_cmp_s(const t_vec3 one, const t_real two)
{
	if (fabs(one.x - two) < M_EPSILON
		&& fabs(one.y - two) < M_EPSILON
		&& fabs(one.z - two) < M_EPSILON)
		return (true);
	return (false);
}
