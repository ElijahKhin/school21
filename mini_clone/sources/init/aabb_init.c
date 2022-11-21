/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:55:29 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:55:30 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shapes.h>

t_bool	volume_init(t_aabb *volume)
{
	const t_vec3	vec_max = (t_vec3){M_INFINITY, M_INFINITY, M_INFINITY};
	const t_vec3	vec_min = (t_vec3){-M_INFINITY, -M_INFINITY, -M_INFINITY};

	volume->using = true;
	volume->min = vec_max;
	volume->max = vec_min;
	return (true);
}
