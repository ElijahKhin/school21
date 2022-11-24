/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:49:32 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:49:34 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer.h>
#include <libft.h>

t_bool	destroy_buffer(t_buffer *buf, void *mlx_ptr)
{
	mlx_destroy_image(mlx_ptr, buf->image);
	ft_memset(&buf, 0, sizeof(t_buffer *));
	return (true);
}
