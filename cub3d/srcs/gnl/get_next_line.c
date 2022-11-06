/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 13:13:53 by scoach            #+#    #+#             */
/*   Updated: 2021/11/19 17:28:36 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_rest_form(char ***rest)
{
	int	i;

	*rest = malloc(sizeof(char *) * 1024);
	if (*rest == NULL)
		return (-1);
	i = 0;
	while (i < 1024)
	{
		(*rest)[i] = ft_calloc(sizeof(char), 1);
		if ((*rest)[i] == NULL)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_buf_read(int fd, char **rest)
{
	char	*tmp;
	char	buf[1001];
	int		ret;

	ret = read(fd, buf, 1000);
	buf[ret] = '\0';
	tmp = ft_substr(*rest, 0, ft_strlen(*rest));
	free(*rest);
	*rest = ft_strjoin(tmp, buf);
	free(tmp);
	return (ret);
}

int	ft_rest_work(char **rest, char **line)
{
	int		i;
	char	*tmp;
	size_t	len;

	i = 0;
	while ((*rest)[i] != '\0' && (*rest)[i] != '\n')
		i++;
	len = ft_strlen(*rest) - i + 1;
	*line = ft_substr(*rest, 0, i);
	if (*line == NULL)
		return (-1);
	if ((*rest)[i] == '\n')
	{
		tmp = ft_substr(*rest, i + 1, len);
		free(*rest);
		*rest = ft_substr(tmp, 0, len);
		free(tmp);
		return (1);
	}
	return (0);
}

int	ft_get_next_line(int fd, char **line)
{
	static char	**rest;
	int			res;
	int			ret;

	if (read(fd, 0, 0) == -1 || line == NULL)
		return (ft_free_all(fd, &rest, -1));
	if (rest == NULL)
		res = ft_rest_form(&rest);
	res = ft_rest_work(&(rest[fd]), line);
	ret = 1000;
	if (res == -1)
		return (ft_free_all(fd, &rest, -1));
	while (res == 0 && ret == 1000)
	{
		ret = ft_buf_read(fd, &(rest[fd]));
		free(*line);
		res = ft_rest_work(&(rest[fd]), line);
	}
	if (res <= 0)
		return (ft_free_all(fd, &rest, res));
	return (res);
}
