/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_material.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:27:53 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:27:54 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <parse.h>

t_bool	parse_material(t_scene *scene, char **line, t_material *mat)
{
	(void)scene;
	if (!parse_color(line, &mat->diffuse))
		return (false);
	return (true);
}

#endif
