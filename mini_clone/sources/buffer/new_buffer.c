/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:50:16 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:50:17 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>
#include <unistd.h>
#include <error.h>

t_bool	new_buffer(t_buffer *buf, void *mlx_ptr,
	const int width, const int height)
{
	buf->width = width;
	buf->height = height;
	buf->image = mlx_new_image(mlx_ptr, width, height);
	if (buf->image == NULL)
		return (error_set_null(buf, "Failed to load image into buffer"));
	buf->address = mlx_get_data_addr(buf->image,
			&buf->bpp, &buf->row_size, &buf->endian);
	buf->size = buf->width * buf->row_size + buf->height * 4;
	return (true);
}
