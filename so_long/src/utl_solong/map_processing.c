/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:27:56 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/06 13:49:34 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	map_uploading(t_map_data *map_data)
{
	char	*line;
	int		fd;

	line = "";
	map_data->path_map = ft_strjoin("src/utl_solong/maps/", map_data->name);
	map_data->map_in_one_line = ft_strdup("");
	map_data->height = 0;
	fd = open(map_data->path_map, O_RDONLY);
	if (fd == -1)
		print_error("ERROR: fd = -1, Wrong Map Name!");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		map_data->map_in_one_line = gnl_strjoin(
				map_data->map_in_one_line, line);
		map_data->height++;
		free(line);
	}
	free(line);
	close(fd);
	if (map_data->map_in_one_line[0] == '\0')
		print_error("ERROR: Map Is Empty");
	map_data->splited_map = ft_split(map_data->map_in_one_line, '\n');
}

void	check_file_extension(char *file_name)
{
	char	*sub;

	sub = ft_substr(file_name, lb_strlen(file_name)-4, 4);
	if (ft_strncmp(sub, ".ber", 4) != 0)
		print_error("ERROR: wrong extension\n");
	free(sub);
}

void	map_processing(t_map_data *map_data)
{
	check_file_extension(map_data->name);
	map_uploading(map_data);
	map_validation(map_data);
}
