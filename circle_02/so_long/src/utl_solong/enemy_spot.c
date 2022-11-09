/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_spot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 14:31:00 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/06 15:16:22 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_spot_1(t_map_data *map_data, int x, int y)
{
	if (map_data->splited_map[y - 1][x - 1] == '0' &&
		map_data->splited_map[y - 1][x] == '0' &&
		map_data->splited_map[y - 1][x + 1] == '0')
	{
		map_data->enemy.enemy_x = x - 1;
		map_data->enemy.enemy_y = y - 1;
		map_data->enemy.move_right = map_data->enemy.enemy_x + 2;
		map_data->enemy.move_left = map_data->enemy.enemy_x;
	}
}

void	check_spot_2(t_map_data *map_data, int x, int y)
{
	if (map_data->splited_map[y + 1][x - 1] == '0' &&
		map_data->splited_map[y + 1][x] == '0' &&
		map_data->splited_map[y + 1][x + 1] == '0')
	{
		map_data->enemy.enemy_x = x - 1;
		map_data->enemy.enemy_y = y + 1;
		map_data->enemy.move_right = map_data->enemy.enemy_x + 2;
		map_data->enemy.move_left = map_data->enemy.enemy_x;
	}
}

void	check_enemies_spots(t_map_data *map_data, int x, int y)
{
	check_spot_1(map_data, x, y);
	if (!map_data->enemy.move_right)
		check_spot_2(map_data, x, y);
}

void	defend_gate(t_map_data *map_data)
{
	int	runner;
	int	notcountn;

	runner = 0;
	notcountn = 0;
	while (map_data->map_in_one_line[runner] != 'E')
	{
		if (map_data->map_in_one_line[runner++] != '\n')
			notcountn++;
	}
	check_enemies_spots(map_data, notcountn % map_data->width,
		notcountn / map_data->width);
}
