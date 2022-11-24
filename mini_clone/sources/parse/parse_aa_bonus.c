/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_aa_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:26:45 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:26:46 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <parse.h>
# include <error.h>

t_bool	parse_aa(t_scene *scene, char **line)
{
	if (scene->aa_enable == true)
		return (error_msg(ERR_AA_EXISTS));
	scene->aa_enable = true;
	if (!parse_int(line, &scene->aa_samples)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_bool(line, &scene->aa_accel)
		|| !parse_eol(line))
		return (false);
	if (scene->aa_samples > 64)
		warning_msg(WARN_AA_SAMPLES);
	return (true);
}

#endif
