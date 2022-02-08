/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_check_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfelwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:47:19 by tfelwood          #+#    #+#             */
/*   Updated: 2022/02/07 20:56:21 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width_correct(t_print_info *info)
{
	va_list	copy;

	va_copy(copy, info->args);
	if (info->flags & 2 || info->flags & 4)
		--info->width;
	if ((*info->format == 'd' || *info->format == 'i')
		&& va_arg(copy, int) < 0)
		--info->width;
	if (info->flags & 8)
		info->width -= 2;
	va_end(copy);
}

static void	ft_check_zero(t_print_info *info)
{
	va_list	copy;

	va_copy(copy, info->args);
	if (info->prec == 0)
	{
		if ((ft_is_number(*info->format)) && !va_arg(copy, int))
			info->flags |= 32;
		else if (*info->format == 'p' && !va_arg(copy, void *))
			info->flags |= 64;
	}
	va_end(copy);
}

static void	ft_input_wid_prec(t_print_info *info)
{
	info->width = ft_atoi(info);
	if (*info->format == '.')
	{
		++info->format;
		info->prec = ft_atoi(info);
	}
	if (*info->format == 'p')
		info->flags |= 8;
}

static void	ft_check_input(t_print_info *info)
{
	va_list	copy;

	va_copy(copy, info->args);
	ft_check_zero(info);
	if (info->flags & 1 || (ft_is_number(*info->format)
			&& info->prec >= 0))
		info->flags &= ~16;
	if (!ft_is_hex(*info->format)
		|| (*info->format != 'p' && !va_arg(copy, unsigned int)))
		info->flags &= ~8;
	if (!(*info->format == 'd' || *info->format == 'i'))
	{
		info->flags &= ~4;
		info->flags &= ~2;
	}
	if (!(info->flags & 64) && !ft_is_number(*info->format)
		&& *info->format != 's' && *info->format != 'p')
		info->prec = -1;
	va_end(copy);
	ft_width_correct(info);
}

void	ft_input_format(t_print_info *info)
{
	while (*info->format && (*info->format == '-' || *info->format == '+'
			|| *info->format == ' ' || *info->format == '#'
			|| *info->format == '0'))
	{
		if (*info->format == '-')
			info->flags |= 1;
		else if (*info->format == '+')
			info->flags |= 2;
		else if (*info->format == ' ')
			info->flags |= 4;
		else if (*info->format == '#')
			info->flags |= 8;
		else if (*info->format == '0')
			info->flags |= 16;
		++info->format;
	}
	ft_input_wid_prec(info);
	ft_check_input(info);
}
