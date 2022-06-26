/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:46:56 by fhiedi            #+#    #+#             */
/*   Updated: 2022/06/26 16:19:25 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_map_data map_data;
//	t_vars vars;

	if (argc != 2)
	{
		ft_printf("ERROR: argc != 2\n");
		exit(1);
	}
	map_data.name = argv[1];
	map_processing(&map_data);
	ft_printf("name of map: %s\n", map_data.name);
	ft_printf("path of map: %s\n", map_data.path_map);
	ft_printf("map in one line: %s\n", map_data.map_in_one_line);
	ft_printf("first line of splited map: %s\n", map_data.splited_map[0]);
	ft_printf("height of map: %d\n", map_data.height);
	free(map_data.path_map);
	free(map_data.map_in_one_line);
	while(*map_data.splited_map)
		free(*map_data.splited_map++);
	exit(0);
}
