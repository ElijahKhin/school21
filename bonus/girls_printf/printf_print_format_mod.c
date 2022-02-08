/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print_format_mod.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfelwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:46:08 by tfelwood          #+#    #+#             */
/*   Updated: 2021/12/26 09:10:35 by tfelwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_format_sign(t_print_info *info)
{
	va_list	copy;

	if (info->flags & 8)
	{
		if (*info->format == 'x' || *info->format == 'p')
			info->count += write(1, "0x", 2);
		else if (*info->format == 'X')
			info->count += write(1, "0X", 2);
		info->flags &= ~8;
	}
	if (*info->format == 'd' || *info->format == 'i')
	{
		va_copy(copy, info->args);
		if (va_arg(copy, int) < 0)
			info->count += write(1, "-", 1);
		else if (info->flags & 2)
			info->count += write(1, "+", 1);
		else if (info->flags & 4)
			info->count += write(1, " ", 1);
		va_end(copy);
	}
}

static void	ft_print_width(t_print_info *info)
{
	char		symb;

	symb = ' ';
	if (info->prec < info->width)
	{
		if (info->flags & 16)
			symb = '0';
		info->width = info->width - info->prec;
		while (info->width-- > 0)
		{
			write(1, &symb, 1);
			++info->count;
		}
	}
	info->width = 0;
}

static void	ft_prec_cor(t_print_info *info, int size)
{
	if (size > info->prec && (*info->format != 's' || info->prec < 0))
		info->prec = size;
	else if (size < info->prec && *info->format == 's')
		info->prec = size;
}

void	ft_print_format_mod(t_print_info *info)
{
	int	size;

	if (!(info->flags & 32) && !(info->flags & 64))
		size = ft_get_size(info);
	else
		size = 0;
	ft_prec_cor(info, size);
	if (info->flags & 16)
		ft_print_format_sign(info);
	if (!(info->flags & 1))
		ft_print_width(info);
	if (!(info->flags & 16))
		ft_print_format_sign(info);
	while (size++ < info->prec)
		write(1, "0", 1);
	info->count += info->prec;
	if (!(info->flags & 32) && !(info->flags & 64))
		ft_print_modifier(info);
	if (info->flags & 1)
		ft_print_width(info);
	if (info->flags & 32)
		va_arg(info->args, int);
	else if (info->flags & 64)
		va_arg(info->args, void *);
	++info->format;
}
