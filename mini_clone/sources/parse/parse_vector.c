/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:29:02 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:29:04 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>

t_bool	parse_vector(char **line, t_vec3 *vector)
{
	if (!parse_real(line, &vector->x)
		|| !parse_skip(line, ",", 1)
		|| !parse_real(line, &vector->y)
		|| !parse_skip(line, ",", 1)
		|| !parse_real(line, &vector->z)
		|| !parse_unused(line))
		return (error_msg(ERR_VEC_FAILURE));
	return (true);
}
