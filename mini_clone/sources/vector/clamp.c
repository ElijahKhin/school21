/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:35:29 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:35:30 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <utils.h>

t_vec3	vec3_clamp(t_vec3 in, const t_real min, const t_real max)
{
	in.x = clamp(in.x, min, max);
	in.y = clamp(in.y, min, max);
	in.z = clamp(in.z, min, max);
	return (in);
}
