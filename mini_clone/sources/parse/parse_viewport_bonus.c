/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_viewport_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:29:06 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:29:08 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>
#include <libft.h>

t_bool	parse_viewport(t_scene *scene, char **line)
{
	char	*input;

	input = parse_id(line);
	if (ft_match(input, VP_FULL))
		scene->viewport_scale = 1;
	else if (ft_match(input, VP_HALF))
		scene->viewport_scale = 2;
	else if (ft_match(input, VP_QUARTER))
		scene->viewport_scale = 4;
	else
		return (error_free(ERR_VP_SCALE, input));
	free(input);
	return (parse_eol(line));
}
