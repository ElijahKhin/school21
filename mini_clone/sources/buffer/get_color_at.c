/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:49:57 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:49:58 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <buffer.h>
#include <unistd.h>

t_rgb	get_color_at(const t_buffer *buf, const int u, const int v)
{
	char	*location;

	location = get_addr_loc(buf, u, v);
	if (location == NULL)
		return (vec3_zero());
	return (data_to_rgb(*(unsigned int *)location));
}
