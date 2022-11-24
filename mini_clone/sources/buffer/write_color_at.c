/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_color_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:50:37 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:50:38 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <buffer.h>

void	write_color_at(t_buffer *buf, const int u, const int v,
	const t_rgb color)
{
	char		*location;

	location = get_addr_loc(buf, u, v);
	*(unsigned int *)location = rgb_to_data(vec3_clamp(color, 0, 1));
}
