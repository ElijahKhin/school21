/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_threads_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:28:46 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:28:47 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>

t_bool	parse_threads(t_scene *scene, char **line)
{
	if (scene->brdf_threading == true)
		return (error_msg(ERR_THR_EXISTS));
	scene->brdf_threading = true;
	if (!parse_int(line, &scene->brdf_threadnum)
		|| !parse_eol(line))
		return (false);
	if (scene->brdf_threadnum <= 0)
		return (error_msg(ERR_INVALID_THRDNUM));
	return (true);
}
