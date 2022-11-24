/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:21:48 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:21:49 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>

t_bool	hit(t_shapes *shape, t_hitrecord *rec, t_real distance)
{
	rec->ref = shape;
	rec->distance = distance;
	return (true);
}
