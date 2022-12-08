/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:07:06 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/08 20:30:10 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding_one(t_arginfo *info)
{
	if (info->spec == 'c' || info->spec == 's')
	{
		info->width = info->width - info->arg_len;
		appendix(info);
	}
}

void	padding_two(t_arginfo *info)
{
	if (info->precision != -1)
	{
		if (info->precision >= info->arg_len)
		{
			info->width = info->width - info->precision;
			if (info->minus && info->left_padding != 1)
				info->width--;
		}
		else
			info->width = info->width - info->arg_len;
	}
	else
		info->width = info->width - info->arg_len;
	if (info->minus && info->left_padding == 1)
		info->width -= 1;
	appendix(info);
}

void	appendix(t_arginfo *info)
{
	while (info->width-- > 0)
	{
		if (info->zero_padding)
			info->printed += write(1, "0", 1);
		else
			info->printed += write(1, " ", 1);
	}
}
