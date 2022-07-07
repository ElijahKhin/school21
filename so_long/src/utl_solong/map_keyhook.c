/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_keyhook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:41:40 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/06 14:25:52 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	utl_collect(t_map_data *map_data)
{
	map_data->splited_map
	[map_data->player_y / 50][map_data->player_x / 50] = '0';
	map_data->collect--;
	put_image(map_data, map_data->player_x,
		map_data->player_y, "src/utl_solong/img/floor.xpm");
	if (map_data->collect == 0)
		open_exit(map_data);
}

void	go_right(t_map_data *map_data)
{
	char	in_front_of;
	char	staying_on;

	in_front_of = map_data->splited_map
	[map_data->player_y / 50][map_data->player_x / 50 + 1];
	put_image(map_data, map_data->player_x,
		map_data->player_y, "src/utl_solong/img/floor.xpm");
	if (in_front_of == 'E' && map_data->collect == 0)
		you_were_born_to_win(map_data);
	if (in_front_of != '1' && in_front_of != 'E')
	{
		map_data->player_x += 50;
		rewrite_string(map_data);
	}
	staying_on = map_data->splited_map
	[map_data->player_y / 50][map_data->player_x / 50];
	if (staying_on == 'C')
		utl_collect(map_data);
	put_image(map_data, map_data->player_x,
		map_data->player_y, "src/utl_solong/img/right.xpm");
}

void	go_left(t_map_data *map_data)
{
	char	in_front_of;
	char	staying_on;

	in_front_of = map_data->splited_map
	[map_data->player_y / 50][map_data->player_x / 50 - 1];
	put_image(map_data, map_data->player_x,
		map_data->player_y, "src/utl_solong/img/floor.xpm");
	if (in_front_of == 'E' && map_data->collect == 0)
		you_were_born_to_win(map_data);
	if (in_front_of != '1' && in_front_of != 'E')
	{
		map_data->player_x -= 50;
		rewrite_string(map_data);
	}
	staying_on = map_data->splited_map
	[map_data->player_y / 50][map_data->player_x / 50];
	if (staying_on == 'C')
		utl_collect(map_data);
	put_image(map_data, map_data->player_x,
		map_data->player_y, "src/utl_solong/img/left.xpm");
}

void	go_up(t_map_data *map_data)
{
	char	in_front_of;
	char	staying_on;

	in_front_of = map_data->splited_map
	[map_data->player_y / 50 - 1][map_data->player_x / 50];
	put_image(map_data, map_data->player_x,
		map_data->player_y, "src/utl_solong/img/floor.xpm");
	if (in_front_of == 'E' && map_data->collect == 0)
		you_were_born_to_win(map_data);
	if (in_front_of != '1' && in_front_of != 'E')
	{
		map_data->player_y -= 50;
		rewrite_string(map_data);
	}
	staying_on = map_data->splited_map
	[map_data->player_y / 50][map_data->player_x / 50];
	if (staying_on == 'C')
		utl_collect(map_data);
	put_image(map_data, map_data->player_x,
		map_data->player_y, "src/utl_solong/img/back.xpm");
}

void	go_down(t_map_data *map_data)
{
	char	in_front_of;
	char	staying_on;

	in_front_of = map_data->splited_map
	[map_data->player_y / 50 + 1][map_data->player_x / 50];
	put_image(map_data, map_data->player_x,
		map_data->player_y, "src/utl_solong/img/floor.xpm");
	if (in_front_of == 'E' && map_data->collect == 0)
		you_were_born_to_win(map_data);
	if (in_front_of != '1' && in_front_of != 'E')
	{
		map_data->player_y += 50;
		rewrite_string(map_data);
	}
	staying_on = map_data->splited_map
	[map_data->player_y / 50][map_data->player_x / 50];
	if (staying_on == 'C')
		utl_collect(map_data);
	put_image(map_data, map_data->player_x,
		map_data->player_y, "src/utl_solong/img/front.xpm");
}
