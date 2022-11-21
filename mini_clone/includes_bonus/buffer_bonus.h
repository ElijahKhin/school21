/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:52:16 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:52:18 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_BONUS_H
# define BUFFER_BONUS_H
# if IS_BONUS == 1

/*
**	initialize a new image buffer using a xpm reference
**	buffer type will be set to b_missing if the image file cannot be found
*/
t_bool	new_tex_buffer(t_buffer *buf, void *mlx_ptr, char *filename);

/*
**	Retrieve the color of texture using texture coordinates <u> and <v>
*/
t_rgb	get_uv_color_at(t_buffer *buf, t_real u, t_real v);

# endif
#endif
