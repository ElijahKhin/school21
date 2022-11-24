/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:52:26 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:52:27 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

unsigned int	rgb_to_data(const t_rgb color)
{
	int		r;
	int		g;
	int		b;

	r = (double)(color.x * 255);
	g = (double)(color.y * 255);
	b = (double)(color.z * 255);
	return (r << 16 | g << 8 | b);
}
