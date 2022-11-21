/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:50:45 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:50:46 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H
# include <buffer.h>

/*
**	Save bmp file from buffer *buf as outfile *filename
*/
t_bool		save_bmp(t_buffer *buf, char *filename);

/*
**	Device independant header containing:
**	-	Size of DIB header in bytes
**	-	Image width
**	-	Image height
**	-	Number of color planes (always 1)
**	-	Bits per pixel. i chose 32 instead of 24 to get around padding
**	-	Pixel compression (0x00000000 if unused, we don't want compression)
**	-	Raw bitmap data size (in bytes)
**	-	Print resolution of the image (horizontal)
**	-	Print resolution of the image (vertical)
**	-	Colors the image can contain
**	-	Important colors in image (0 = all)
*/
t_bool		write_dib_header(t_buffer *buf, int fd);

/*
**	bmp header file containing:
**	-	'BM' marker used to verify binary data is a bitmap file
**	-	Filesize
**	-	Unused
**	-	Unused
**	-	Offset to pixel array (depending on header size, 54 in this case)
**		in bytes
*/
t_bool		write_bmp_header(t_buffer *buf, int fd);

#endif
