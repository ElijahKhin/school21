/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder_cap_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:27:16 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:27:17 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <libft.h>
# include <parse.h>
# include <error.h>
# include <math.h>

t_bool	parse_cylinder_cap(t_scene *scene, char **line)
{
	t_cylinder	*cylinder;
	t_material	mat;

	cylinder = (t_cylinder *)ft_calloc(1, sizeof(t_cylinder));
	if (cylinder == NULL)
		return (error_msg(ERR_ALLOC_CYLINDER));
	if (!parse_vector(line, &cylinder->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_normal(line, &cylinder->normal)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &cylinder->radius)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &cylinder->height)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_material(scene, line, &mat)
		|| !parse_eol(line))
		return (parse_failure(cylinder));
	cylinder->capped = true;
	cylinder->radius = fabs(cylinder->radius) * 0.5;
	cylinder->height = fabs(cylinder->height);
	return (shape_push_back(&scene->shapes, cylinder, mat, sh_cylinder));
}

#endif
