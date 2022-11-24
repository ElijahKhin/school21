/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:51:37 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:51:38 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include <vector.h>
# include <alias.h>

typedef struct s_ray
{
	t_vec3		origin;
	t_vec3		dir;
	t_real		min;
	t_real		max;
}	t_ray;

#endif
