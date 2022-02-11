/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:41 by fhiedi            #+#    #+#             */
/*   Updated: 2022/02/11 16:51:44 by fhiedi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int		runner;
	int		printed;
	va_list	arg_ptr;

	runner = 0;
	printed = 0;
	va_start(arg_ptr, format);
	while (format[runner] != '\0')
	{
		if (format[runner] == '%')
		{
			printed += print_arg(format[++runner], arg_ptr);
			runner++;
		}
		else
			printed += write(1, &format[runner++], 1);
	}
	return (printed);
}

