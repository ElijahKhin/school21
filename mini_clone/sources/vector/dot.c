/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:35:42 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:35:45 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_real	vec3_dot(const t_vec3 one, const t_vec3 two)
{
	return (one.x * two.x + one.y * two.y + one.z * two.z);
}