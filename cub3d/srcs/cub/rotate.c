/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 03:41:10 by chasimir          #+#    #+#             */
/*   Updated: 2022/03/17 19:30:50 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	rotate_l(t_raycast *raycast)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = raycast->dir_x;
	old_plane_x = raycast->plane_x;
	raycast->dir_x = raycast->dir_x * cos(-raycast->rot_speed)
		- raycast->dir_y * sin(-raycast->rot_speed);
	raycast->dir_y = old_dir_x * sin(-raycast->rot_speed)
		+ raycast->dir_y * cos(-raycast->rot_speed);
	raycast->plane_x = raycast->plane_x * cos(-raycast->rot_speed)
		- raycast->plane_y * sin(-raycast->rot_speed);
	raycast->plane_y = old_plane_x * sin(-raycast->rot_speed)
		+ raycast->plane_y * cos(raycast->rot_speed);
}

void	rotate_r(t_raycast *raycast)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = raycast->dir_x;
	old_plane_x = raycast->plane_x;
	raycast->dir_x = raycast->dir_x * cos(raycast->rot_speed)
		- raycast->dir_y * sin(raycast->rot_speed);
	raycast->dir_y = old_dir_x * sin(raycast->rot_speed)
		+ raycast->dir_y * cos(raycast->rot_speed);
	raycast->plane_x = raycast->plane_x * cos(raycast->rot_speed)
		- raycast->plane_y * sin(raycast->rot_speed);
	raycast->plane_y = old_plane_x * sin(raycast->rot_speed)
		+ raycast->plane_y * cos(raycast->rot_speed);
}
