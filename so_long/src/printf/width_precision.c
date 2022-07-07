/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:49:19 by fhiedi            #+#    #+#             */
/*   Updated: 2022/04/11 20:14:11 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width(t_arginfo *info)
{
	info->width = 0;
	while (ft_isdigit(info->format[info->index]))
		info->width = (info->width + (info->format[info->index++] - 48)) * 10;
	info->width /= 10;
}

void	precision(t_arginfo *info)
{
	info->precision = -1;
	if (info->format[info->index] == '.')
	{
		info->zero_padding = 0;
		info->precision = 0;
		while (ft_isdigit(info->format[++info->index]))
			info->precision = (info->precision
					+ (info->format[info->index] - 48)) * 10;
		info->precision /= 10;
	}
}
