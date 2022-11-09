/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:26:30 by fhiedi            #+#    #+#             */
/*   Updated: 2022/01/17 21:56:38 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	iter(char *join)
{
	int	run;

	run = 0;
	if (!join)
		return (0);
	while (join[run] && join[run] != '\n')
		run++;
	if (join[run] == '\n')
		return (1);
	return (0);
}

char	*get_short_join(char *join)
{
	char	*ret;
	int		r;
	int		ar;

	r = 0;
	while (join[r] && join[r] != '\n')
		r++;
	if (!join[r])
	{
		free(join);
		return (NULL);
	}
	ret = (char *)malloc(sizeof(char) * (ft_strlen(join) - r + 1));
	if (!ret)
		return (NULL);
	r++;
	ar = 0;
	while (join[r])
		ret[ar++] = join[r++];
	ret[ar] = '\0';
	free(join);
	return (ret);
}

char	*get_ret_string(char *join)
{
	int		run;
	char	*ret_string;

	run = 0;
	if (!join[run])
		return (NULL);
	while (join[run] && join[run] != '\n')
		run++;
	ret_string = (char *)malloc(sizeof(char) * (run + 2));
	if (!ret_string)
		return (NULL);
	run = 0;
	while (join[run] && join[run] != '\n')
	{
		ret_string[run] = join[run];
		run++;
	}
	if (join[run] == '\n')
		ret_string[run++] = '\n';
	ret_string[run] = '\0';
	return (ret_string);
}

char	*get_line(int fd)
{
	static char	*join[257];
	char		*ret_string;
	int			end;
	char		*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	end = 1;
	while (!iter(join[fd]) && end != 0)
	{
		end = read(fd, buf, BUFFER_SIZE);
		if (end == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[end] = '\0';
		join[fd] = ft_strjoin(join[fd], buf);
	}
	free(buf);
	ret_string = get_ret_string(join[fd]);
	join[fd] = get_short_join(join[fd]);
	return (ret_string);
}

char	*get_next_line(int fd)
{
	if (fd < 0 || fd > 256 || BUFFER_SIZE < 1)
		return (NULL);
	return (get_line(fd));
}
