/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:17:39 by chasimir          #+#    #+#             */
/*   Updated: 2022/03/16 20:17:40 by chasimir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	pixel_put(t_pixel *pixel, int x, int y, int color)
{
	char	*dst;

	dst = pixel->addr + (y * pixel->line_len + x * (pixel->bpp / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel_color(t_textures *txt, int x, int y)
{
	int	color;

	color = *(unsigned int *)(txt->img_data
			+ (y * txt->line_len + x * (txt->bpp / 8)));
	return (color);
}
