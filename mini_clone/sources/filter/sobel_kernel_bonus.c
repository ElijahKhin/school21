/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sobel_kernel_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:54:55 by fhiedi            #+#    #+#             */
/*   Updated: 2022/11/19 18:40:17 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <alias.h>
#include <math.h>
#include <color.h>

t_real	sobel5x5(int idx1, int idx2, int xy)
{
	static t_real	sobel5[5][5] = {
	{-0.5, -1.0, 0.0, 1.0, 0.5},
	{-0.5, -1.0, 0.0, 1.0, 0.5},
	{-1.0, -2.0, 0.0, 2.0, 1.0},
	{-0.5, -1.0, 0.0, 1.0, 0.5},
	{-0.5, -1.0, 0.0, 1.0, 0.5}
	};

	if (xy)
		return (sobel5[idx1][idx2]);
	return (sobel5[idx2][idx1]);
}

t_real	sobel3x3(int idx1, int idx2, int xy)
{
	static t_real	sobel3[3][3] = {
	{-1.0, 0.0, 1.0},
	{-2.0, 0.0, 2.0},
	{-1.0, 0.0, 1.0}
	};

	if (xy)
		return (sobel3[idx1][idx2]);
	return (sobel3[idx2][idx1]);
}

t_rgb	sobel_sum3(t_rgb x, t_rgb y)
{
	return ((t_vec3){
		sqrt((x.x * x.x) + (y.x * y.x)),
		sqrt((x.y * x.y) + (y.y * y.y)),
		sqrt((x.z * x.z) + (y.z * y.z))});
}

t_real	sobel_sum(t_real x, t_real y)
{
	return (sqrt(x * x + y * y));
}
