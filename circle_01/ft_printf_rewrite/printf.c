/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/12/08 20:30:22 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_arginfo	info;

	info.index = -1;
	info.printed = 0;
	info.format = format;
	va_start(info.arg_ptr, format);
	while (info.format[++info.index] != '\0')
	{
		if (info.format[info.index] == '%')
		{
			get_info(&info);
			check_print(&info);
		}
		else
			info.printed += write(1, &info.format[info.index], 1);
	}
	va_end(info.arg_ptr);
	return (info.printed);
}
