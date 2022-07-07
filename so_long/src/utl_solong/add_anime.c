/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_anime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:57:16 by fhiedi            #+#    #+#             */
/*   Updated: 2022/07/06 15:18:01 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	rotate_img(t_map_data *map_data)
{
	int	num_img;

	map_data->enemy.img_sleep = 0;
	num_img = map_data->enemy.num_img;
	map_data->enemy.imgs[0] = "src/utl_solong/img/1.xpm";
	map_data->enemy.imgs[1] = "src/utl_solong/img/2.xpm";
	map_data->enemy.imgs[2] = "src/utl_solong/img/3.xpm";
	map_data->enemy.imgs[3] = "src/utl_solong/img/2.xpm";
	map_data->enemy.imgs[4] = "src/utl_solong/img/1.xpm";
	put_image(map_data, map_data->enemy.enemy_x * 50,
		map_data->enemy.enemy_y * 50, "src/utl_solong/img/floor.xpm");
	put_image(map_data, map_data->enemy.enemy_x * 50,
		map_data->enemy.enemy_y * 50, map_data->enemy.imgs[num_img]);
}

void	move_enemy(t_map_data *map_data)
{
	if (map_data->enemy.rotate_sign)
	{
		put_image(map_data, map_data->enemy.enemy_x * 50,
			map_data->enemy.enemy_y * 50, "src/utl_solong/img/floor.xpm");
		map_data->enemy.enemy_x--;
		map_data->enemy.delay_img = 0;
		if (map_data->enemy.enemy_x == map_data->enemy.move_left)
			map_data->enemy.rotate_sign = 0;
	}
	else
	{
		if (!map_data->enemy.rotate_sign)
		{
			put_image(map_data, map_data->enemy.enemy_x * 50,
				map_data->enemy.enemy_y * 50, "src/utl_solong/img/floor.xpm");
			map_data->enemy.enemy_x++;
			map_data->enemy.delay_img = 0;
			if (map_data->enemy.enemy_x == map_data->enemy.move_right)
				map_data->enemy.rotate_sign = 1;
		}
	}
}

void	you_were_born_to_suck(t_map_data *map_data)
{
	ft_printf("\n-------------------------------");
	ft_printf("-------------------------------------------\n");
	ft_printf("                  Sorry, But You Were Born To Suck:(");
	ft_printf("\n                      \n ");
	ft_printf("	                     Game Over!\n");
	ft_printf("------------------------------");
	ft_printf("--------------------------------------------\n");
	free_all(map_data);
}

void	you_were_born_to_win(t_map_data *map_data)
{
	ft_printf("\n------------------------------------");
	ft_printf("--------------------------------------\n");
	ft_printf("                  Congrants, My Little Warrior:)");
	ft_printf("\n                      \n     ");
	ft_printf("	            	    You Won!\n");
	ft_printf("------------------------");
	ft_printf("--------------------------------------------------\n");
	free_all(map_data);
}

int	add_anime(t_map_data *map_data)
{
	if (map_data->enemy.num_img++ == 4)
		map_data->enemy.num_img = 0;
	if (map_data->enemy.img_sleep++ == 1000)
		rotate_img(map_data);
	if (map_data->player_x == map_data->enemy.enemy_x * 50
		&& map_data->player_y == map_data->enemy.enemy_y * 50)
		you_were_born_to_suck(map_data);
	map_data->enemy.delay_img++;
	if (map_data->enemy.delay_img == 5000)
		move_enemy(map_data);
	return (0);
}
