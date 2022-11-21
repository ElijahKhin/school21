/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:27:07 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:27:08 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>

t_bool	parse_color(char **line, t_rgb *color)
{
	int		col[3];

	if (!parse_int(line, &col[0])
		|| !parse_skip(line, ",", 1)
		|| !parse_int(line, &col[1])
		|| !parse_skip(line, ",", 1)
		|| !parse_int(line, &col[2])
		|| !parse_unused(line))
		return (false);
	color->x = (t_real)(col[0]) / 255;
	color->y = (t_real)(col[1]) / 255;
	color->z = (t_real)(col[2]) / 255;
	if (vec3_grt(*color, 1.0) || vec3_lss(*color, 0.0))
		return (error_msg(ERR_PAR_COL));
	return (true);
}
