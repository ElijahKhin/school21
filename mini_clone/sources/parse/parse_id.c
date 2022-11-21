/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:27:25 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:27:26 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 0
# include <parse.h>
# include <libft.h>

char	*parse_id(char **line)
{
	char	*id;
	int		len;

	*line += ft_strspn(*line, DELIM_SPACE);
	if (**line == '\0')
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
