/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:55:50 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 17:55:51 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>
#include <libft.h>

/*
**	defaults
*/

t_bool	material_init(t_material *mat)
{
	ft_memset(mat, 0, sizeof(t_material));
	mat->specular = (t_vec3){1.0, 1.0, 1.0};
	mat->gloss = 0.75;
	mat->reflection = (t_vec3){0.2, 0.2, 0.2};
	mat->emission = (t_vec3){0.0, 0.0, 0.0};
	mat->roughness = 0.5;
	mat->tex_size_y = 1.0;
	mat->tex_size_x = 1.0;
	return (true);
}
