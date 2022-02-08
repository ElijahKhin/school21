/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfelwood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:50:35 by tfelwood          #+#    #+#             */
/*   Updated: 2021/12/26 00:08:28 by tfelwood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_info_clean(t_print_info *info)
{
	info->flags = 0;
	info->width = 0;
	info->prec = -1;
}

int	ft_printf(const char *format, ...)
{
	t_print_info	pr_inf;

	pr_inf.count = 0;
	ft_info_clean(&pr_inf);
	pr_inf.format = format;
	va_start(pr_inf.args, format);
	while (*pr_inf.format)
	{
		if (*pr_inf.format != '%')
		{
			write(1, pr_inf.format++, 1);
			++pr_inf.count;
		}
		else
		{
			++pr_inf.format;
			ft_input_format(&pr_inf);
			if (*pr_inf.format)
				ft_print_format_mod(&pr_inf);
			ft_info_clean(&pr_inf);
		}
	}
	va_end(pr_inf.args);
	return (pr_inf.count);
}
