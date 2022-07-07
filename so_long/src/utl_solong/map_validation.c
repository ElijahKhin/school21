/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:27:08 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/06 16:57:28 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_elements(t_map_data *map_data)
{
	int		runner;
	char	some_char;
	char	*right_set;
	int		result;

	right_set = "PEC10\n";
	runner = 0;
	map_data->width = lb_strlen(map_data->splited_map[0]);
	while (map_data->map_in_one_line[runner])
	{
		some_char = map_data->map_in_one_line[runner++];
		if (!ft_charinstr(right_set, some_char))
			print_error("ERROR: Unacceptable element");
		result = which_element(some_char);
	}
	if (!result)
		print_error("ERROR: Need more elements");
}

void	check_rectangular(t_map_data *map_data)
{
	int	runner;
	int	standard_len;

	runner = 0;
	standard_len = lb_strlen(map_data->splited_map[runner++]);
	while (map_data->splited_map[runner])
	{
		if (lb_strlen(map_data->splited_map[runner++]) != standard_len)
			print_error("ERROR: Map isn't rectangular");
	}
}

void	check_walls(t_map_data *map_data)
{
	int	runner;

	runner = 0;
	while (map_data->splited_map[0][runner])
	{
		if ((map_data->splited_map[0][runner] != '1')
			|| (map_data->splited_map[map_data->height - 1][runner++] != '1'))
			print_error("ERROR: Map isn't surrounded by walls!");
	}
	runner = 0;
	while (map_data->splited_map[runner])
	{
		if ((map_data->splited_map[runner][0] != '1')
			|| (map_data->splited_map[runner++]
				[lb_strlen(map_data->splited_map[0]) - 1] != '1'))
			print_error("ERROR: Map isn't surrounded by walls!");
	}
}

void	map_validation(t_map_data *map_data)
{
	check_elements(map_data);
	check_rectangular(map_data);
	check_walls(map_data);
}
