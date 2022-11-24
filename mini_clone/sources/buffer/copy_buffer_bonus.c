/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_buffer_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:49:24 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:49:25 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>

t_bool	copy_buffer(t_buffer *in, void *mlx_ptr, t_buffer *out)
{
	int		u;
	int		v;

	u = 0;
	v = 0;
	if (mlx_ptr)
	{
		if (new_buffer(out, mlx_ptr, in->width, in->height) == false)
			return (false);
	}
	while (u < in->width)
	{
		while (v < in->height)
		{
			write_color_at(out, u, v, get_color_at(in, u, v));
			v += 1;
		}
		v = 0;
		u += 1;
	}
	return (true);
}
