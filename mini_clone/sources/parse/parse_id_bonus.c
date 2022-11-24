/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:27:36 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 19:09:30 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <libft.h>
# include <parse.h>

/*
**	parse ID and return, to compare
**	also, comments!
*/

char	*parse_id(char **line)
{
	char	*id;
	int		len;

	*line += ft_strspn(*line, DELIM_SPACE);
	if (**line == '\0' || **line == '#')
		return (NULL);
	len = ft_strcspn(*line, DELIM_SPACE);
	if (len == 0)
		return (NULL);
	id = (char *)ft_calloc(1, len + 1);
	ft_memcpy(id, *line, len);
	*line += len;
	*line += ft_strspn(*line, DELIM_SPACE);
	return (id);
}

#endif
