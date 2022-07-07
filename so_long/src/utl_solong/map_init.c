/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:14:22 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/06 16:57:06 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	fill_map_data(t_map_data *map_data)
{
	map_data->collect = 0;
	map_data->movement = 0;
	map_data->enemy.num_img = 0;
	map_data->enemy.delay_img = 0;
	map_data->enemy.move_left = 0;
	map_data->enemy.move_right = 0;
	map_data->enemy.rotate_sign = 0;
	map_data->enemy.img_sleep = 0;
}

void	put_image(t_map_data *map_data, int width_px,
		int height_px, char *img_path)
{
	int	img_w;
	int	img_h;

	map_data->img = mlx_xpm_file_to_image(map_data->mlx,
			img_path, &img_w, &img_h);
	mlx_put_image_to_window(map_data->mlx,
		map_data->win, map_data->img, width_px, height_px);
}

void	put_image_floor(t_map_data *map_data, int width_px, int height_px)
{
	put_image(map_data, width_px, height_px,
		"src/utl_solong/img/floor.xpm");
}

void	put_image_to_map(char element, int width_px,
		int height_px, t_map_data *map_data)
{
	if (element == '1')
		put_image(map_data, width_px, height_px,
			"src/utl_solong/img/wall.xpm");
	else if (element == 'C')
	{
		put_image_floor(map_data, width_px, height_px);
		put_image(map_data, width_px, height_px,
			"src/utl_solong/img/collect.xpm");
		map_data->collect++;
	}
	else if (element == 'E')
		put_image(map_data, width_px, height_px,
			"src/utl_solong/img/exit.xpm");
	else if (element == 'P')
	{
		map_data->player_x = width_px;
		map_data->player_y = height_px;
		put_image_floor(map_data, width_px, height_px);
		put_image(map_data, width_px, height_px,
			"src/utl_solong/img/front.xpm");
	}
	else
		put_image_floor(map_data, width_px, height_px);
}

void	map_rendering(t_map_data *map_data)
{
	int	runner;
	int	notcountn;

	runner = 0;
	notcountn = 0;
	while (map_data->map_in_one_line[runner])
	{
		put_image_to_map(map_data->map_in_one_line[runner],
			notcountn % map_data->width * 50,
			notcountn / map_data->width * 50, map_data);
		if (map_data->map_in_one_line[runner] != '\n')
			notcountn++;
		runner++;
	}
}
