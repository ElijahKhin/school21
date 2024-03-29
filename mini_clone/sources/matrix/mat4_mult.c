/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_mult.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:25:50 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:25:52 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

/*
**	Useful for combining rotation matrices, thats the only thing really
*/

t_mat4	mat4_mult(t_mat4 src, t_mat4 mult)
{
	t_mat4		out;
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			out.data[i][j] = src.data[i][0] * mult.data[0][j]
				+ src.data[i][1] * mult.data[1][j]
				+ src.data[i][2] * mult.data[2][j]
				+ src.data[i][3] * mult.data[3][j];
			j++;
		}
		i++;
	}
	return (out);
}
