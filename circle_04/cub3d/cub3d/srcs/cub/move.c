/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:50:06 by chasimir          #+#    #+#             */
/*   Updated: 2022/03/17 19:41:04 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	move_a(t_raycast *raycast)
{
	if (raycast->main->map[(int)raycast->pos_y]
		[(int)(raycast->pos_x - raycast->plane_x * 0.11f)] != '1')
			raycast->pos_x -= raycast->plane_x * raycast->move_speed;
	if (raycast->main->map[(int)(raycast->pos_y - raycast->plane_y * 0.11f)]
		[(int)raycast->pos_x] != '1')
		raycast->pos_y -= raycast->plane_y * raycast->move_speed;
}

void	move_d(t_raycast *raycast)
{
	if (raycast->main->map[(int)raycast->pos_y]
		[(int)(raycast->pos_x + raycast->plane_x * 0.11f)] != '1')
			raycast->pos_x += raycast->plane_x * raycast->move_speed;
	if (raycast->main->map[(int)(raycast->pos_y + raycast->plane_y * 0.11f)]
		[(int)(raycast->pos_x)] != '1')
		raycast->pos_y += raycast->plane_y * raycast->move_speed;
}

void	move_s(t_raycast *raycast)
{
	if (raycast->main->map[(int)raycast->pos_y]
		[(int)(raycast->pos_x - raycast->dir_x * 0.11f)] != '1')
			raycast->pos_x -= raycast->dir_x * raycast->move_speed;
	if (raycast->main->map[(int)(raycast->pos_y - raycast->dir_y * 0.11f)]
		[(int)raycast->pos_x] != '1')
		raycast->pos_y -= raycast->dir_y * raycast->move_speed;
}

void	move_w(t_raycast *raycast)
{
	if (raycast->main->map[(int)raycast->pos_y]
		[(int)(raycast->pos_x + raycast->dir_x * 0.11f)] != '1')
			raycast->pos_x += raycast->dir_x * raycast->move_speed;
	if (raycast->main->map[(int)(raycast->pos_y + raycast->dir_y * 0.11f)]
		[(int)raycast->pos_x] != '1')
		raycast->pos_y += raycast->dir_y * raycast->move_speed;
}
