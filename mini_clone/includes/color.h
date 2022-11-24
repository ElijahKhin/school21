/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:50:50 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:50:51 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include <vector.h>
# if IS_BONUS == 1
#  include <color_bonus.h>
# endif

typedef t_vec3	t_rgb;

# if IS_BONUS == 0

typedef struct s_material
{
	t_rgb		diffuse;
}	t_material;

# endif

/*
**	convert 8byte pixel data into t_rgb struct (with values of unit length)
*/
t_rgb			data_to_rgb(const unsigned int color);

/*
**	convert t_rgb struct into 8byte pixel data
*/
unsigned int	rgb_to_data(const t_rgb color);

/*
**	check if t_rgb is actually within its bounds: [0.0 - 1.0]
*/
t_bool			check_color(const t_rgb color);

#endif
