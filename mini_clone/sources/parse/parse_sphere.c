/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:28:26 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:28:29 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>
#include <libft.h>
#include <math.h>

t_bool	parse_sphere(t_scene *scene, char **line)
{
	t_sphere	*sphere;
	t_material	mat;

	sphere = (t_sphere *)ft_calloc(1, sizeof(t_sphere));
	if (sphere == NULL)
		return (error_msg(ERR_ALLOC_SPHERE));
	if (!parse_vector(line, &sphere->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &sphere->radius)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_material(scene, line, &mat)
		|| !parse_eol(line))
		return (parse_failure(sphere));
	sphere->radius = fabs(sphere->radius * 0.5);
	return (shape_push_back(&scene->shapes, sphere, mat, sh_sphere));
}
