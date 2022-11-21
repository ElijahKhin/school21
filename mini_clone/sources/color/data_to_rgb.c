/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_to_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:52:20 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:52:21 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

t_rgb	data_to_rgb(const unsigned int color)
{
	t_rgb		rgb;

	rgb.x = ((color >> 16) & 0xFF) / 255.0;
	rgb.y = ((color >> 8) & 0xFF) / 255.0;
	rgb.z = ((color) & 0xFF) / 255.0;
	return (rgb);
}
