/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:28:51 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:28:53 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>
#include <libft.h>

t_bool	parse_triangle(t_scene *scene, char **line)
{
	t_triangle	*tri;
	t_material	mat;

	tri = (t_triangle *)ft_calloc(1, sizeof(t_triangle));
	if (tri == NULL)
		return (error_msg(ERR_ALLOC_TRIANGLE));
	if (!parse_vector(line, &tri->vert[0])
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_vector(line, &tri->vert[1])
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_vector(line, &tri->vert[2])
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_material(scene, line, &mat)
		|| !parse_eol(line))
		return (parse_failure(tri));
	return (shape_push_back(&scene->shapes, tri, mat, sh_triangle));
}
