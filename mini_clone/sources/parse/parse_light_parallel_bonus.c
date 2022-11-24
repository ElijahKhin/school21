/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light_parallel_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:27:46 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:27:48 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <error.h>
# include <libft.h>
# include <parse.h>

t_bool	parse_light_parallel(t_scene *scene, char **line)
{
	t_lights	*light;

	light = (t_lights *)ft_calloc(1, sizeof(t_lights));
	if (light == NULL)
		return (error_msg(ERR_ALLOC_LIGHT));
	if (!parse_vector(line, &light->origin)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_vector(line, &light->normal)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_unit(line, &light->intensity, false)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_color(line, &light->color)
		|| !parse_eol(line))
		return (parse_failure(light));
	light->color = vec3_mult_s(light->color, light->intensity);
	return (light_push_back(&scene->lights, light));
}

#endif
