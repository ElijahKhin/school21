/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:38:23 by fhiedi            #+#    #+#             */
/*   Updated: 2022/04/11 20:11:39 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_left(t_arginfo *info)
{
	info->left_padding = 0;
	if (info->format[++info->index] == '-')
	{
		info->left_padding = 1;
		info->padding = 1;
		while (info->format[info->index] == '-')
			++info->index;
		while (info->format[info->index] == '0')
			++info->index;
	}
}

void	flag_plus(t_arginfo *info)
{
	info->plus = 0;
	while (info->format[info->index] == '+')
	{
		info->plus = 1;
		++info->index;
		if (info->format[info->index] == ' ')
			++info->index;
	}
}

void	flag_zero(t_arginfo *info)
{
	info->zero_padding = 0;
	if (info->format[info->index] == '0')
	{
		info->zero_padding = 1;
		info->padding = 1;
		while (info->format[info->index] == '0')
			info->index++;
	}
}

void	flag_space(t_arginfo *info)
{
	info->space = 0;
	while (info->format[info->index] == ' ')
	{
		info->space = 1;
		++info->index;
	}
}

void	flag_sharp(t_arginfo *info)
{
	info->sharp = 0;
	if (info->format[info->index] == '#')
	{
		info->sharp = 1;
		++info->index;
	}
}
