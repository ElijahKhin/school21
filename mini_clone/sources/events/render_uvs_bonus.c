/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_uvs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:17:20 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:17:22 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_uvs(t_scene *scene)
{
	scene->viewport = uvs;
	console_put(DEBUG_UV);
	return (true);
}
