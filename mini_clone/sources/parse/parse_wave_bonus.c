/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wave_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:29:11 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:29:12 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <error.h>
#include <libft.h>

t_bool	parse_wave(char **line, t_wave *wave)
{
	char	*uv;

	uv = parse_id(line);
	if (ft_match(uv, "uv") || ft_match(uv, "vu"))
		wave->using = (t_vec2){1.0, 1.0};
	else if (ft_match(uv, "u"))
		wave->using = (t_vec2){1.0, 0.0};
	else if (ft_match(uv, "v"))
		wave->using = (t_vec2){0.0, 1.0};
	else
		return (error_free(ERR_WAVE_UV, uv));
	free(uv);
	if (!parse_unit(line, &wave->amp, false)
		|| !parse_skip(line, DELIM_SPACE, 0)
		|| !parse_real(line, &wave->freq)
		|| !parse_eol(line))
		return (false);
	return (true);
}
