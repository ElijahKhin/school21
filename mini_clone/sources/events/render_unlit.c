/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_unlit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:17:16 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:17:18 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

t_bool	render_unlit(t_scene *scene)
{
	scene->viewport = unlit;
	console_put(DEBUG_UNLIT);
	return (true);
}
