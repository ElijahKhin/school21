/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:35:05 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:35:07 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <math.h>

t_vec3	vec3_abs(const t_vec3 vector)
{
	return ((t_vec3){fabs(vector.x), fabs(vector.y), fabs(vector.z)});
}
