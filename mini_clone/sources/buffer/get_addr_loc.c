/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_addr_loc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:49:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:49:42 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>

char	*get_addr_loc(const t_buffer *buf, const int u, const int v)
{
	char	*location;

	location = buf->address
		+ (v * buf->row_size
			+ u * (buf->bpp / COLOR_SIZE));
	return (location);
}
