/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:29:53 by scoach            #+#    #+#             */
/*   Updated: 2022/03/22 18:35:24 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int	ft_parse_texture(t_data *data, char **tmp)
{
	int	i;
	int	fd;

	i = -1;
	if (tmp[0][0] == 'N' && tmp[0][1] == 'O')
		i = 0;
	if (tmp[0][0] == 'S' && tmp[0][1] == 'O')
		i = 1;
	if (tmp[0][0] == 'W' && tmp[0][1] == 'E')
		i = 2;
	if (tmp[0][0] == 'E' && tmp[0][1] == 'A')
		i = 3;
	if (i >= 0 && data->nswe[i] == NULL)
		data->nswe[i] = ft_strdup(tmp[1]);
	else
		return (1);
	if (data->nswe[i] == NULL)
		return (1);
	fd = open(data->nswe[i], O_RDONLY);
	if (fd == -1)
		return (1);
	else if (close(fd) == -1)
		return (1);
	return (0);
}

static int	ft_data_write(t_data *data, char ***tmp, int strln)
{
	if (strln == 2)
		return (ft_parse_texture(data, *tmp));
	if ((*tmp)[0][0] == 'F' && data->floor == -1)
		ft_parse_rgb(data, tmp, &(data->floor), 0);
	else if ((*tmp)[0][0] == 'C' && data->ceilling == -1)
		ft_parse_rgb(data, tmp, &(data->ceilling), 0);
	else
		return (1);
	return (0);
}

static void	ft_check_write_params(t_data *data, char **line, int *check)
{
	char	***tmp;
	int		sln;
	int		aln;

	tmp = malloc(sizeof(char **));
	if (tmp == NULL)
		ft_error(data, "ft_check_write_params malloc", 0);
	*tmp = ft_split(*line, ' ');
	aln = ft_arrlen(*tmp);
	if (*tmp == NULL)
		ft_context_free_err(data, tmp, aln, "ft_split malloc");
	if (aln > 0)
		sln = ft_strlen((*tmp)[0]);
	if (aln < 2 || sln > 2 || sln < 1 || ft_data_write(data, tmp, sln))
		ft_context_free_err(data, tmp, aln, "Wrong map parameters");
	ft_free_arr(*tmp, 2);
	free(tmp);
	(*check)++;
}

void	ft_parse_params(t_data *data, int *gnl, int fd)
{
	int		i;
	int		check;

	data->gnln = ft_calloc(1, sizeof (char *));
	if (data->gnln == NULL)
		ft_error(data, "ft_parse_params malloc", 0);
	*data->gnln = ft_calloc(1, 1);
	if (*data->gnln == NULL)
		ft_error(data, "ft_parse_params malloc", 0);
	i = 0;
	check = 0;
	data->floor = -1;
	data->ceilling = -1;
	while (*gnl != 0 && check != 6)
	{
		ft_gnl_read(data, gnl, fd, data->gnln);
		if ((*data->gnln) != NULL && (*data->gnln)[0] != '\n'
			&& (*data->gnln)[0] != '\0')
			ft_check_write_params(data, data->gnln, &check);
		i++;
	}
	if (check != 6)
		ft_error(data, "Not enough argumetns", 0);
}
