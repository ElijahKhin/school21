/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_path_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:34:35 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:34:36 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if IS_BONUS == 1
# include <libft.h>
# include <parse.h>

char	*trim_path(char **line)
{
	char		*ret;
	int			size;
	int			idx;

	if (**line == '\"')
	{
		*line += 1;
		size = ft_strcspn(*line, DELIM_QUOT);
	}
	else
		size = ft_strcspn(*line, DELIM_SPACE);
	ret = (char *)ft_calloc(1, size + 1);
	idx = 0;
	while (idx < size)
	{
		ret[idx] = **line;
		idx += 1;
		*line += 1;
	}
	if (**line == '\"')
		*line += 1;
	return (ret);
}

#endif
