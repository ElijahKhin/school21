/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:28:04 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:28:05 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>
#include <libft.h>

t_bool	parse_plane(t_scene *scene, char **line)
{
	t_plane		*plane;
	t_material	mat;

	plane = (t_plane *)ft_calloc(1, sizeof(t_plane));
	if (plane == NULL)
		return (error_msg(ERR_ALLOC_PLANE));
	if (!parse_vector(line, &plane->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_normal(line, &plane->normal)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_material(scene, line, &mat)
		|| !parse_eol(line))
		return (parse_failure(plane));
	return (shape_push_back(&scene->shapes, plane, mat, sh_plane));
}
