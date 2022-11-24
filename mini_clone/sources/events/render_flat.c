/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_flat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:17:01 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:17:03 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_flat(t_scene *scene)
{
	console_put(DEBUG_FLAT);
	scene->viewport = flat;
	return (true);
}
