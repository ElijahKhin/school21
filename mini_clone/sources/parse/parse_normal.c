/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:28:00 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:28:01 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>

t_bool	parse_normal(char **line, t_vec3 *normal)
{
	if (!parse_vector(line, normal))
		return (false);
	if (vec3_grt(*normal, 1.0) || vec3_lss(*normal, -1.0))
		return (error_msg(ERR_INVALID_NORMAL));
	if (vec3_cmp(*normal, vec3_zero()))
		return (error_msg(ERR_ZERO_NORMAL));
	*normal = vec3_unit(*normal);
	return (true);
}
