/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tex_buffer_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:50:25 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:50:26 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>

t_bool	new_tex_buffer(t_buffer *buf, void *mlx_ptr, char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 3)
		return (false);
	close(fd);
	buf->image = mlx_xpm_file_to_image(mlx_ptr, filename,
			&buf->width, &buf->height);
	if (buf->image == NULL)
		return (error_set_null(buf, "Failed to load image into buffer"));
	buf->address = mlx_get_data_addr(buf->image,
			&buf->bpp, &buf->row_size, &buf->endian);
	return (true);
}
