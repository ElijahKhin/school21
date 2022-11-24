/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:32:17 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:32:18 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <jump_tables.h>

t_rgb	shade(t_scene *scene, t_hitrecord *rec)
{
	t_rgb	col;

	col = vec3_zero();
	jump_shader(scene, rec, &col);
	return (col);
}
