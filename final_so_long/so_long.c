/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:46:56 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/06 14:52:34 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_map_data *map_data)
{
	if (keycode == 2 || keycode == 124)
		go_right(map_data);
	if (keycode == 0 || keycode == 123)
		go_left(map_data);
	if (keycode == 13 || keycode == 126)
		go_up(map_data);
	if (keycode == 1 || keycode == 125)
		go_down(map_data);
	if (keycode == 53)
		free_all(map_data);
	return (0);
}

void	start_game(t_map_data *map_data)
{
	map_data->mlx = mlx_init();
	map_data->win = mlx_new_window(map_data->mlx,
			map_data->width * 50, map_data->height * 50, "So_Long");
	map_rendering(map_data);
	mlx_hook(map_data->win, 3, 0, key_hook, map_data);
	mlx_hook(map_data->win, 17, 0, free_all, map_data);
	mlx_string_put(map_data->mlx,
		map_data->win, 5, 10, 0xffffff, "Current Move: 0");
	mlx_loop_hook(map_data->mlx, add_anime, map_data);
	mlx_loop(map_data->mlx);
}

int	main(int argc, char **argv)
{
	t_map_data	map_data;

	if (argc != 2)
		print_error("ERROR: argc != 2\n");
	map_data.name = argv[1];
	map_processing(&map_data);
	fill_map_data(&map_data);
	defend_gate(&map_data);
	start_game(&map_data);
}
