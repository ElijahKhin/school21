/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_skip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:28:19 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:28:20 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <error.h>

t_bool	parse_skip(char **line, const char *delim, int skip_count)
{
	int		len;

	len = ft_strspn(*line, delim);
	if (!len)
		return (error_msg(ERR_PAR_DELIM));
	if (skip_count && len == skip_count)
		*line += skip_count;
	else
		*line += len;
	return (true);
}
