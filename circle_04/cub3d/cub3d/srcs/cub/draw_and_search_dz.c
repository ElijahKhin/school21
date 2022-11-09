/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_and_search_dz.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:04:12 by chasimir          #+#    #+#             */
/*   Updated: 2022/03/17 19:41:04 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_line(t_raycast *raycast, t_textures *txt, int y, int x)
{
	int	c;

	c = 0;
	raycast->step = (1.0f * TEXTURE_HEIGHT / raycast->line_height);
	raycast->tex_pos = (float)((raycast->draw_start - SCREEN_HEIGHT / 2
				+ raycast->line_height / 2) * raycast->step);
	while (c < raycast->draw_start)
	{
		pixel_put(raycast->pixel, x, c, raycast->main->ceilling);
		c++;
	}
	while (y <= raycast->draw_end)
	{
		raycast->tex_y = (int)raycast->tex_pos & (TEXTURE_HEIGHT - 1);
		raycast->tex_pos += raycast->step;
		pixel_put(raycast->pixel, x, y, get_pixel_color(txt,
				TEXTURE_WIDTH - raycast->tex_x - 1, raycast->tex_y));
		y++;
	}
	while (raycast->draw_end < SCREEN_HEIGHT)
	{
		pixel_put(raycast->pixel, x, raycast->draw_end, raycast->main->floor);
		raycast->draw_end++;
	}
}

void	seach_draw_and_txt(t_raycast *raycast)
{
	if (!raycast->side)
	{
		raycast->perp_wall_dist = raycast->side_dist_x - raycast->delta_dist_x;
		raycast->wall_x = raycast->pos_y
			+ raycast->perp_wall_dist * raycast->raydir_y;
	}
	else
	{
		raycast->perp_wall_dist = raycast->side_dist_y - raycast->delta_dist_y;
		raycast->wall_x = raycast->pos_x
			+ raycast->perp_wall_dist * raycast->raydir_x;
	}
	raycast->wall_x -= floorf(raycast->wall_x);
	raycast->tex_x = (int)(raycast->wall_x * (float)TEXTURE_WIDTH);
	if (!raycast->side && raycast->raydir_x > 0)
		raycast->tex_x = TEXTURE_WIDTH - raycast->tex_x - 1;
	if (raycast->side && raycast->raydir_y < 0)
		raycast->tex_x = TEXTURE_WIDTH - raycast->tex_x - 1;
	raycast->line_height = (int)(SCREEN_HEIGHT / raycast->perp_wall_dist);
	raycast->draw_start = -raycast->line_height / 2 + SCREEN_HEIGHT / 2;
	if (raycast->draw_start < 0)
		raycast->draw_start = 0;
	raycast->draw_end = raycast->line_height / 2 + SCREEN_HEIGHT / 2;
	if (raycast->draw_end >= SCREEN_HEIGHT)
		raycast->draw_end = SCREEN_HEIGHT - 1;
}

void	choice_txt(t_raycast *raycast, t_data *main, int x)
{
	t_textures	*txt;

	if (!raycast->side && raycast->map_x < raycast->pos_x)
		txt = main->west;
	if (!raycast->side && raycast->map_x >= raycast->pos_x)
		txt = main->east;
	if (raycast->side && raycast->map_y < raycast->pos_y)
		txt = main->north;
	if (raycast->side && raycast->map_y >= raycast->pos_y)
		txt = main->south;
	draw_line(raycast, txt, raycast->draw_start, x);
}
