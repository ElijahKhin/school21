/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_units_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:17:12 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:17:14 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_units(t_scene *scene)
{
	scene->viewport = units;
	console_put(DEBUG_UNITS);
	return (true);
}
