/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_unused.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:28:56 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:28:58 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <error.h>

t_bool	parse_eol(char **line)
{
	int		len;

	len = ft_strspn(*line, DELIM_SPACE);
	if (len == 0 || **line == '\0')
		return (true);
	*line += len;
	if (**line == '\0')
		return (true);
	return (error_msg(ERR_UNUSED_PARAM));
}

t_bool	parse_unused(char **line)
{
	if (ft_strchr(DELIM_SPACE, **line))
		return (true);
	return (error_msg(ERR_UNUSED_PARAM));
}
