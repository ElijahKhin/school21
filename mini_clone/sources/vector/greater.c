/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:35:47 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:35:48 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>

t_bool	vec3_grt(const t_vec3 vector, const t_real number)
{
	if (vector.x > number || vector.y > number || vector.z > number)
		return (true);
	return (false);
}
