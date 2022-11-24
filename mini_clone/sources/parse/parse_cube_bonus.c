/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cube_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:27:10 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:27:11 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <libft.h>
# include <parse.h>
# include <unistd.h>
# include <error.h>
# include <math.h>

t_bool	parse_cube(t_scene *scene, char **line)
{
	t_cube		*cube;
	t_material	mat;

	cube = (t_cube *)ft_calloc(1, sizeof(t_cube));
	if (cube == NULL)
		return (error_msg(ERR_ALLOC_CUBE));
	if (!parse_vector(line, &cube->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_normal(line, &cube->normal)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &cube->size)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_material(scene, line, &mat)
		|| !parse_eol(line))
		return (parse_failure(cube));
	cube->size = fabs(cube->size);
	return (shape_push_back(&scene->shapes, cube, mat, sh_cube));
}

#endif
